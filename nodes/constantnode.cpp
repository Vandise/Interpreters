#include "constantnode.hpp"
#include "../runtime/stdclass.hpp"
#include "../context.hpp"

Nodes::ConstantNode::ConstantNode(std::string name)
{
  this->name = name;
}

Runtime::Object*
Nodes::ConstantNode::eval(Context *context)
{
  return context->getCurrentClass()->getConstant(this->name);
}