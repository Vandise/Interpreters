#ifndef __INTERPRETEDMETHOD_HPP__
#define __INTERPRETEDMETHOD_HPP__ 1

#include <string>
#include <map>
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
    std::map<int, std::string> parameters;

  public:
    InterpretedMethod(std::string name, std::map<int, std::string> parameters, Nodes::AbstractNode *body);
    Runtime::Object* call(Runtime::Object *receiver, std::map<int, Runtime::Object*> arguments);
    
};

#endif