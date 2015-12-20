#include "literalnode.hpp"
#include "../context.hpp"

Nodes::LiteralNode::LiteralNode(Runtime::Object* value)
{
  this->value = value;
}

Runtime::Object*
Nodes::LiteralNode::eval(Context *context)
{
  return this->value;
}