#include "instancevariablenode.hpp"
#include "../runtime/stdclass.hpp"
#include "../context.hpp"

Nodes::InstanceVariableNode::InstanceVariableNode(std::string name)
{
  this->name = name;
}

Runtime::Object*
Nodes::InstanceVariableNode::eval(Context *context)
{
  return context->getCurrentSelf()->getInstanceVariable(name);
}