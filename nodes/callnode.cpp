#include "callnode.hpp"
#include "../runtime/stdclass.hpp"
#include "../context.hpp"

Nodes::CallNode::CallNode(std::string method, AbstractNode *receiver, std::map<int, AbstractNode*> arguments)
{
  this->method = method;
  this->receiver = receiver;
  this->arguments = arguments;
}

Runtime::Object*
Nodes::CallNode::eval(Context *context)
{
  std::map<int, Runtime::Object*> evalArguments;
  std::map<int, AbstractNode*>::iterator it;
  for ( it = this->arguments.begin(); it != this->arguments.end(); it++ )
  {
    Runtime::Object *evalArg = it->second->eval(context);
    evalArguments[it->first] = evalArg;
  }

  Runtime::Object *evalReciever = this->receiver->eval(context);
  return evalReciever->call(this->method, evalArguments);
}