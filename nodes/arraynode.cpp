#include "arraynode.hpp"
#include "../runtime.hpp"
#include "../context.hpp"
#include "../runtime/stdclass.hpp"
#include "../runtime/array.hpp"
#include <iostream>

Nodes::ArrayNode::ArrayNode(std::vector<Nodes::AbstractNode*> elements)
{
  this->elements = elements;
}

Runtime::Object*
Nodes::ArrayNode::eval(Context *context)
{
  std::vector<Runtime::Object*> evaled_elements;
  for(int i = 0; i < this->elements.size(); i++)
  {
    evaled_elements.push_back(this->elements[i]->eval(context));
  }
  return new Runtime::ArrayObject(evaled_elements, context);
}