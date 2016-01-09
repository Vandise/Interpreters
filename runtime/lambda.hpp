#ifndef __LAMBDAOBJECT_HPP__
#define __LAMBDAOBJECT_HPP__ 1

#include "object.hpp"
#include <string>
#include <vector>

class Context;

namespace Nodes{
  class AbstractNode;
}
namespace Runtime
{
  class Object;
  class StdClass;
  
  class LambdaObject : public Object
  {
    private:
      Nodes::AbstractNode        *body;
      std::vector<std::string>   parameters;
      Context                    *context;
    public:
      LambdaObject(std::vector<std::string> parameters, Nodes::AbstractNode *body, Context *context);
      Object* eval(std::vector<Runtime::Object*> arguments);
  };
}

#endif