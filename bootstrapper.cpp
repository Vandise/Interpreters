#include "bootstrapper.hpp"

#include <iostream>
#include <cstdlib>
#include  "context.hpp"
#include "runtime/stdclass.hpp"
#include "runtime/integer.hpp"

Context*
Bootstrapper::run()
{
  Runtime::StdClass *objectClass = new Runtime::StdClass("Object");
  Lang::Runtime::objectClass = objectClass;

  Runtime::Object *main = new Runtime::Object();
  Lang::Runtime::mainObject = main;

  Runtime::StdClass *classClass = new Runtime::StdClass("Class");
  objectClass->setStdClass(classClass); // object is a class
  classClass->setStdClass(classClass); // class is a class
  main->setStdClass(objectClass);

  objectClass->setConstant("Object", objectClass); // woo recursion! 
  objectClass->setConstant("Class", classClass);

  Lang::Runtime::nilObject    = objectClass->newSubclass(std::string("NilClass"))->newInstance(0);
  Lang::Runtime::trueObject   = objectClass->newSubclass(std::string("TrueClass"))->newInstance(1);
  Lang::Runtime::falseObject  = objectClass->newSubclass(std::string("FalseClass"))->newInstance(0);
  Runtime::StdClass *intClass = objectClass->newSubclass(std::string("Integer"));

  intClass->addMethod(std::string("+"),&int_add_method);
  intClass->addMethod(std::string("-"),&int_subtract_method);
  intClass->addMethod(std::string("<"),&int_less_than_method);
  //std::cout << intClass->hasMethod(std::string("+"));

  std::map<int, Runtime::Object*> arguments;
  Runtime::ValueObject *valobj = new Runtime::ValueObject(1);
  arguments[0] = new Runtime::ValueObject(1);
  Runtime::Object *returnValue = int_add_method.call(valobj, arguments);

  //std::cout << valobj->call(std::string("+"),arguments)->getValue();

  /*
    Object
      klass = Lang::Runtime::getRootClass("Integer")
        => ObjectClass->getConstant("Integer") -> constants["Integer"]
        => StdClass "Integer"
            -> Methods["+", method_struct ptr]
        
    1 + 1
    Runtime::ValueObject(1).call("+",Runtime::ValueObject(1))
      => 2
  
  */

/*
  std::cout << "\n Val Object Inherits Integer: \n";
  std::cout << valobj->getStdClass()->getName();
  std::cout << "\n";

  std::cout << "Value of returned object: ";
  std::cout << returnValue->getValue();
  std::cout << "\n";
*/
  return new Context(main);
}