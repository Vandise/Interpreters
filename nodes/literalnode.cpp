#include "literalnode.hpp"
#include "../context.hpp"

Nodes::LiteralNode::LiteralNode(Runtime::ValueObject* value)
{
  this->value = value;
}

Runtime::ValueObject*
Nodes::LiteralNode::eval(Context *context)
{
  return this->value;
}