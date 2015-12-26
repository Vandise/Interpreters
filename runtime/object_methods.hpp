#ifndef __OBJECTMETHODS_HPP__
#define __OBJECTMETHODS_HPP__ 1

#include <iostream>
#include <string>
#include "method.hpp"
#include "../runtime.hpp"
#include "valueobject.hpp"

struct GlobalPrint : Method
{
  Runtime::Object* call(Runtime::Object *receiver, std::vector<Runtime::Object*> arguments)
  {
    for(int i = 0; i < arguments.size(); i++)
    {
      std::cout << arguments[i]->getValue();
      std::cout << "\n";
    }
    return Lang::Runtime::getNil();
  }
};

struct GlobalClassInstance : Method
{
  Runtime::Object* call(Runtime::Object *receiver, std::vector<Runtime::Object*> arguments)
  {
    return receiver->getStdClass();
  }
};

GlobalPrint         global_print_method;
GlobalClassInstance global_class_instance;

#endif