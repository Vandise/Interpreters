#ifndef __NODES_HPP__
#define __NODES_HPP__ 1

#include <vector>
#include "abstractnode.hpp"

class Context;

namespace Runtime
{
  class Object;  
}

namespace Nodes
{
  class AbstractNode;
  class Nodes : public AbstractNode
  {
    public:
      std::vector<AbstractNode*> nodes;
    public:
      Nodes(std::vector<AbstractNode*> nodes);
      void add(AbstractNode* node);
      Runtime::Object* eval(Context *context);
      
  };
}

#endif