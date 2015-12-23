#ifndef __CLASSDEFINITIONNODE_HPP__
#define __CLASSDEFINITIONNODE_HPP__ 1

#include <string>
#include "abstractnode.hpp"

class Context;

namespace Runtime
{
  class Object;  
}

namespace Nodes
{
  class ClassDefinitionNode : public AbstractNode
  {
    private:
      std::string  name;
      std::string  superName;
      AbstractNode *body;

    public:
      ClassDefinitionNode(std::string name, std::string superName, AbstractNode *body);
      Runtime::Object* eval(Context *context);
  };
}

#endif