#include "literalnode.hpp"
#include <iostream>

Nodes::LiteralNode::LiteralNode(int value)
{
  this->value = value;
}

void
Nodes::LiteralNode::eval()
{
  std::cout << "Not Yet Implemented";
}