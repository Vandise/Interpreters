#include "nodes.hpp"
#include "abstractnode.hpp"
#include "../context.hpp"
#include "../runtime/stdclass.hpp"

Nodes::Nodes::Nodes()
{
  // do nothing
}

void
Nodes::Nodes::add(AbstractNode* node)
{
  this->nodes.push_back(node);
}

Runtime::Object*
Nodes::Nodes::eval(Context *context)
{
  
}