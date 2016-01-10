#ifndef __ARRAYNODE_HPP__
#define __ARRAYNODE_HPP__ 1

#include <string>
#include <map>
#include <vector>
#include "abstractnode.hpp"

namespace Nodes
{
  class ArrayNode : public AbstractNode
  {
    private:
      std::vector<Nodes::AbstractNode*> elements;

    public:
      ArrayNode(std::vector<Nodes::AbstractNode*> elements);
      Runtime::Object* eval(Context *context);
      
  };
}


#endif