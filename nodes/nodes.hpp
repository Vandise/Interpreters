#ifndef __NODES_HPP__
#define __NODES_HPP__ 1

#include <vector>

class Context;

namespace Runtime
{
  class Object;  
}

namespace Nodes
{
  class AbstractNode;
  class Nodes
  {
    public:
      std::vector<AbstractNode*> nodes;
    public:
      Nodes();
      void add(AbstractNode* node);
      Runtime::Object* eval(Context *context);
      
  };
}

#endif