#ifndef __INSTANCEVARIABLEASSIGNNODE_HPP__
#define __INSTANCEVARIABLEASSIGNNODE_HPP__ 1

#include <string>
#include "abstractnode.hpp"

class Context;

namespace Runtime
{
  class Object;  
}

namespace Nodes
{
  class InstanceVariableAssign : public AbstractNode
  {
    private:
      std::string name;
      AbstractNode *expression;

    public:
      InstanceVariableAssign(std::string name, Nodes::AbstractNode *expression);
      Runtime::Object*  eval(Context *context);
  };
}

#endif