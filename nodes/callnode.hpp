#ifndef __CALLNODE_HPP__
#define __CALLNODE_HPP__ 1

#include <string>
#include <map>

#include "abstractnode.hpp"

class Context;

namespace Runtime
{
  class Object;  
}

namespace Nodes
{
  class AbstractNode;
  class CallNode : public AbstractNode
  {
    private:
      AbstractNode *receiver;
      std::string  method;
      std::map<int, AbstractNode*> arguments;

    public:
      CallNode(std::string method, AbstractNode *receiver, std::map<int, AbstractNode*> arguments);
      Runtime::Object* eval(Context *context);
  };
}

#endif