#include "bootstrapper.hpp"

#include <iostream>
#include <cstdlib>
#include <vector>
#include  "context.hpp"
#include "runtime/class.hpp"
#include "runtime/stdclass.hpp"
#include "runtime/integer.hpp"
#include "runtime/string.hpp"
#include "runtime/object_methods.hpp"
#include "runtime/lambda_methods.hpp"

Context*
Bootstrapper::run()
{
  Runtime::StdClass *classClass = new Runtime::StdClass("Class");
  Runtime::StdClass *objectClass = new Runtime::StdClass("Object", classClass);
  Lang::Runtime::objectClass = objectClass;

  Runtime::Object *main = new Runtime::Object();
  Lang::Runtime::mainObject = main;

  objectClass->setStdClass(objectClass); // object is a class
  classClass->setStdClass(classClass); // class is a class
  main->setStdClass(objectClass);

  objectClass->setConstant("Object", objectClass); // woo recursion! 
  objectClass->setConstant("Class", classClass);

  Lang::Runtime::nilObject    = objectClass->newSubclass(std::string("NilClass"))->newInstance(0);
  Lang::Runtime::trueObject   = objectClass->newSubclass(std::string("TrueClass"))->newInstance(1);
  Lang::Runtime::falseObject  = objectClass->newSubclass(std::string("FalseClass"))->newInstance(0);
  Runtime::StdClass *intClass = objectClass->newSubclass(std::string("Integer"));
  Runtime::StdClass *strClass = objectClass->newSubclass(std::string("String"));
  Runtime::StdClass *lambdaClass = objectClass->newSubclass(std::string("Lambda"));

  classClass->addMethod(std::string("new"),&class_new_method);
  classClass->addMethod(std::string("class_name"),&class_class_name_method);
  classClass->addMethod(std::string("superclass"),&class_super_class_method);

  objectClass->addMethod(std::string("print"),&global_print_method);
  objectClass->addMethod(std::string("class_instance"),&global_class_instance);

  lambdaClass->addMethod(std::string("call"),&lambda_call_method);
  intClass->addMethod(std::string("+"),&int_add_method);
  intClass->addMethod(std::string("-"),&int_subtract_method);
  intClass->addMethod(std::string("*"),&int_multiply_method);
  intClass->addMethod(std::string("/"),&int_divide_method);
  intClass->addMethod(std::string("<"),&int_less_than_method);
  intClass->addMethod(std::string(">"),&int_greater_than_method);

  strClass->addMethod(std::string("*"),&string_multiply_op);
  strClass->addMethod(std::string("+"),&string_plus_op);

  return new Context(main);
}