#include "literalnode.hpp"
#include <iostream>

Nodes::LiteralNode::LiteralNode(Runtime::ValueObject* value)
{
  this->value = value;
}

void
Nodes::LiteralNode::eval()
{
  std::cout << "Not Yet Implemented";
}