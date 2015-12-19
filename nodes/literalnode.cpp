#include "literalnode.hpp"
#include <iostream>

Nodes::LiteralNode::LiteralNode(Runtime::ValueObject* value)
{
  this->value = value;
}

Runtime::ValueObject*
Nodes::LiteralNode::eval()
{
  return this->value;
}