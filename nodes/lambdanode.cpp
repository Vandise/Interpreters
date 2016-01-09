#include "lambdanode.hpp"
#include "../runtime.hpp"
#include "../interpretedmethod.hpp"
#include "../context.hpp"
#include "../runtime/stdclass.hpp"
#include "../runtime/lambda.hpp"
#include <iostream>

Nodes::LambdaNode::LambdaNode(std::vector<std::string> parameters, Nodes::AbstractNode *body)
{
  this->parameters = parameters;
  this->body = body;
}

Runtime::Object*
Nodes::LambdaNode::eval(Context *context)
{
  return new Runtime::LambdaObject(this->parameters, this->body, context);
}