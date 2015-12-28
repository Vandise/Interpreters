#ifndef __INSTANCEVARIABLENODE_HPP__
#define __INSTANCEVARIABLENODE_HPP__ 1

#include <string>
#include "abstractnode.hpp"

class Context;

namespace Runtime
{
  class Object;  
}

namespace Nodes
{
  class InstanceVariableNode : public AbstractNode
  {
    private:
      std::string name;

    public:
      InstanceVariableNode(std::string name);
      Runtime::Object*  eval(Context *context);
  };
}

#endif