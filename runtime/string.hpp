#ifndef __STRING_HPP__
#define __STRING_HPP__ 1

#include <string>
#include "method.hpp"
#include "../runtime.hpp"
#include "valueobject.hpp"

struct StringMultOp: StringOperatorMethod<std::string, int>
{
  Runtime::Object* perform(std::string receiver, int argument)
  {
    std::string value;
    for(int i = 0; i < argument; i++ )
    {
      value += receiver;
    }
    return new Runtime::ValueObject(value);
  }
};

struct StringPlusOp: StringOperatorMethod<std::string, std::string>
{
  Runtime::Object* perform(std::string receiver, std::string argument)
  {
    return new Runtime::ValueObject(receiver + argument);
  }
};

StringMultOp string_multiply_op;
StringPlusOp string_plus_op;

#endif
