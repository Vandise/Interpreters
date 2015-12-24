#ifndef __CLASSMETHODS_HPP__
#define __CLASSMETHODS_HPP__ 1

#include <iostream>
#include <string>
#include "method.hpp"
#include "../runtime.hpp"
#include "valueobject.hpp"

struct ClassNew : Method
{
  Runtime::Object* call(Runtime::Object *receiver, std::vector<Runtime::Object*> arguments)
  {
    Runtime::StdClass *self     = (Runtime::StdClass*)receiver;
    Runtime::Object   *instance = self->newInstance();
    instance->setStdClass(self);
    if(self->hasMethod(std::string("construct")))
    {
      instance->call("construct", arguments);
    }
    return (Runtime::StdClass*)instance;
  }
};

ClassNew class_new_method;

#endif