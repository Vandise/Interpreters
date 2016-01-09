#include "lambda.hpp"
#include "../context.hpp"
#include "../runtime.hpp"
#include "../nodes/abstractnode.hpp"
#include <iostream>

Runtime::LambdaObject::LambdaObject(std::vector<std::string> parameters, Nodes::AbstractNode *body, Context *context)
{
  this->klass = Lang::Runtime::getRootClass(std::string("Lambda"));
  this->parameters = parameters;
  this->body = body;
  this->context = context;
}

Runtime::Object*
Runtime::LambdaObject::eval(std::vector<Runtime::Object*> arguments)
{
  Context *context = new Context(this);

  if(this->parameters.size() != arguments.size())
  {
    throw std::invalid_argument("Invalid argument count for method 'call' in object Lambda");
  }

  for(int i = 0; i < this->parameters.size(); i++)
  {
    context->setLocal(this->parameters[i], arguments[i]);
  }

  return this->body->eval(context);
}