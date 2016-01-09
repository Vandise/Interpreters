#ifndef __LAMBDANODE_HPP__
#define __LAMBDANODE_HPP__ 1

#include <string>
#include <map>
#include <vector>
#include "abstractnode.hpp"

namespace Nodes
{
  class LambdaNode : public AbstractNode
  {
    private:
      AbstractNode               *body;
      std::vector<std::string>   parameters;

    public:
      LambdaNode(std::vector<std::string> parameters, AbstractNode *body);
      Runtime::Object* eval(Context *context);
      
  };
}


#endif