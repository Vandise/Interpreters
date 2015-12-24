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

GlobalPrint global_print_method;

#endif