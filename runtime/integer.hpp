#ifndef __INTEGER_HPP__
#define __INTEGER_HPP__ 1

#include <iostream>
#include "method.hpp"
#include "../runtime.hpp"
#include "valueobject.hpp"

struct IntAddOp: OperatorMethod<int>
{
  Runtime::Object* perform(int receiver, int argument)
  {
    return new Runtime::ValueObject(receiver + argument);
  }
};

struct IntMinusOp: OperatorMethod<int>
{
  Runtime::Object* perform(int receiver, int argument)
  {
    return new Runtime::ValueObject(receiver - argument);
  }
};

struct IntLessThanOp: OperatorMethod<int>
{
  Runtime::Object* perform(int receiver, int argument)
  {
    return Lang::Runtime::toBoolean(receiver < argument);
    //return new Runtime::ValueObject(receiver < argument);
  }
};

IntAddOp       int_add_method;
IntMinusOp     int_subtract_method;
IntLessThanOp  int_less_than_method;

#endif