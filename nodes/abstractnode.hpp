#ifndef __NODE_HPP__
#define __NODE_HPP__ 1

class Context;

namespace Runtime
{
  class Object;  
}

namespace Nodes
{
  class AbstractNode
  {
    public:
      virtual Runtime::Object* eval(Context *context) = 0;
  };
}

#endif