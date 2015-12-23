#ifndef __INTERPRETEDMETHOD_HPP__
#define __INTERPRETEDMETHOD_HPP__ 1

#include <string>
#include <map>
#include <vector>
#include "runtime/method.hpp"

namespace Nodes
{
  class AbstractNode;
}

class InterpretedMethod : public Method
{
  private:
    std::string                name;
    Nodes::AbstractNode        *body;
    std::vector<std::string>   parameters;

  public:
    InterpretedMethod(std::string name, std::vector<std::string> parameters, Nodes::AbstractNode *body);
    Runtime::Object* call(Runtime::Object *receiver, std::vector<Runtime::Object*> arguments);
    
};

#endif