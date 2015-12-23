#ifndef __CONSTANTNODE_HPP__
#define __CONSTANTNODE_HPP__ 1

#include <string>
#include "abstractnode.hpp"

class Context;

namespace Runtime
{
  class Object;  
}

namespace Nodes
{
  class ConstantNode : public AbstractNode
  {
    private:
      std::string name;

    public:
      ConstantNode(std::string name);
      Runtime::Object*  eval(Context *context);
  };
}

#endif