#include "nodes.hpp"
#include <iostream>
#include "../runtime.hpp"
#include "abstractnode.hpp"
#include "../context.hpp"
#include "../runtime/stdclass.hpp"

Nodes::Nodes::Nodes(std::vector<AbstractNode*> nodes)
{
  this->nodes = nodes;
}

void
Nodes::Nodes::add(AbstractNode* node)
{
  this->nodes.push_back(node);
}

Runtime::Object*
Nodes::Nodes::eval(Context *context)
{
  //std::cout << "Total Nodes to eval: ";
  //std::cout << this->nodes.size();
  //std::cout << "\n";

  Runtime::Object *lastEval = Lang::Runtime::nilObject;

  for (auto &n : this->nodes) {
    lastEval = n->eval(context);
  }

  //std::cout << "Returned Class: ";
  //std::cout << lastEval->getStdClass()->getName();
  //std::cout << "\n";
  //std::cout << "value: ";
  //std::cout << lastEval->getValue();
  //std::cout << "\n";

  return lastEval;
}