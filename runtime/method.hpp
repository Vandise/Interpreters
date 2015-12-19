#ifndef __METHOD_HPP__
#define __METHOD_HPP__ 1

#include <map>
#include "valueobject.hpp"
#include <boost/variant/get.hpp>

namespace Runtime
{
  class Object;
  class ValueObject;
}

struct Method
{
  virtual Runtime::Object* call(Runtime::Object *receiver, std::map<int, Runtime::Object*> arguments) = 0;
};

template<typename T>
struct OperatorMethod : Method
{
  Runtime::Object* call(Runtime::Object *receiver, std::map<int, Runtime::Object*> arguments)
  {
    T self     = boost::get<T>(((Runtime::ValueObject*)receiver)->getValue());
    T argument = boost::get<T>(((Runtime::ValueObject*)arguments[0])->getValue());
    return perform(self, argument);
  }

  virtual Runtime::Object* perform(T receiver, T argument);
};

#endif