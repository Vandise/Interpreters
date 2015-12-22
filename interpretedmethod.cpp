#include "runtime/stdclass.hpp"
#include "interpretedmethod.hpp"
#include "nodes/abstractnode.hpp"
#include "context.hpp"
#include <stdexcept>

InterpretedMethod::InterpretedMethod(std::string name, std::map<int, std::string> parameters, Nodes::AbstractNode *body)
{
  this->name = name;
  this->parameters = parameters;
  this->body = body;
}

Runtime::Object*
InterpretedMethod::call(Runtime::Object *receiver, std::map<int, Runtime::Object*> arguments)
{
  Context *context = new Context(receiver);

  if(parameters.size() != arguments.size())
  {
    throw std::invalid_argument("Invalid argument count for method " + this->name);
  }

  for(int i = 0; i < parameters.size(); i++)
  {
    context->setLocal(parameters[i], arguments[i]);
  }

  return this->body->eval(context);
}