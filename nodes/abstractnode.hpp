#ifndef __NODE_HPP__
#define __NODE_HPP__ 1

namespace Runtime
{
  class Object;  
}

namespace Nodes
{
  class AbstractNode
  {
    public:
      virtual Runtime::Object* eval() = 0;
  };
}

#endif