#include "methoddefinitionnode.hpp"
#include "../runtime.hpp"
#include "../interpretedmethod.hpp"
#include "../context.hpp"
#include "../runtime/stdclass.hpp"
#include <iostream>

Nodes::MethodDefinitionNode::MethodDefinitionNode(std::string name, std::vector<std::string> parameters, Nodes::AbstractNode *body)
{
  this->name = name;
  this->parameters = parameters;
  this->body = body;
}

Runtime::Object*
Nodes::MethodDefinitionNode::eval(Context *context)
{
  context->getCurrentClass()->addMethod(this->name,
    new InterpretedMethod(this->name, this->parameters, this->body)
  );
  return Lang::Runtime::nilObject;
}