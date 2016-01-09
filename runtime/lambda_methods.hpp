#ifndef __LAMBDAMETHODS_HPP__
#define __LAMBDAMETHODS_HPP__ 1

#include <iostream>
#include <string>
#include "method.hpp"
#include "../runtime.hpp"
#include "lambda.hpp"

struct LambdaCall : Method
{
  Runtime::Object* call(Runtime::Object *receiver, std::vector<Runtime::Object*> arguments)
  {
    Runtime::LambdaObject* lambdaObject = (Runtime::LambdaObject*)receiver;
    return lambdaObject->eval(arguments);
  }
};

LambdaCall  lambda_call_method;

#endif