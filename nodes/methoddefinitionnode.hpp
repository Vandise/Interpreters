#ifndef __METHODDEFINITIONNODE_HPP__
#define __METHODDEFINITIONNODE_HPP__ 1

#include <string>
#include <map>
#include "abstractnode.hpp"

namespace Nodes
{
  class MethodDefinitionNode : public AbstractNode
  {
    private:
      std::string                name;
      AbstractNode               *body;
      std::map<int, std::string> parameters;

    public:
      MethodDefinitionNode(std::string name, std::map<int, std::string> parameters, AbstractNode *body);
      Runtime::Object* eval(Context *context);
      
  };
}


#endif