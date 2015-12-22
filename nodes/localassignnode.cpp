#include "localassignnode.hpp"
#include "../context.hpp"
#include "../runtime/object.hpp"

Nodes::LocalAssignNode::LocalAssignNode(std::string name, Nodes::AbstractNode *expression)
{
  this->name = name;
  this->expression = expression;
}

Runtime::Object*
Nodes::LocalAssignNode::eval(Context *context)
{
  Runtime::Object *value = expression->eval(context);
  context->setLocal(name, value);
  return value;
}