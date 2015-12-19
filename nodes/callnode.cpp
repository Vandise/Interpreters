#include "callnode.hpp"
#include "abstractnode.hpp"
#include "../runtime/stdclass.hpp"

Nodes::CallNode::CallNode(std::string method, AbstractNode *receiver, std::map<int, AbstractNode*> arguments)
{
  this->method = method;
  this->receiver = receiver;
  this->arguments = arguments;
}

Runtime::Object*
Nodes::CallNode::eval()
{
  std::map<int, Runtime::Object*> evalArguments;
  std::map<int, AbstractNode*>::iterator it;
  for ( it = this->arguments.begin(); it != this->arguments.end(); it++ )
  {
    Runtime::Object *evalArg = it->second->eval();
    evalArguments[it->first] = evalArg;
  }

  Runtime::Object *evalReciever = this->receiver->eval();
  return evalReciever->call(this->method, evalArguments);
}