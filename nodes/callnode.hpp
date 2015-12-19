#ifndef __CALLNODE_HPP__
#define __CALLNODE_HPP__ 1

#include <string>
#include <map>

namespace Runtime
{
  class Object;  
}

namespace Nodes
{
  class AbstractNode;
  class CallNode
  {
    private:
      AbstractNode *receiver;
      std::string  method;
      std::map<int, AbstractNode*> arguments;

    public:
      CallNode(std::string method, AbstractNode *receiver, std::map<int, AbstractNode*> arguments);
      Runtime::Object* eval();
  };
}

#endif