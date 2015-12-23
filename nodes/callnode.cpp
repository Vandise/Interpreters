#include "callnode.hpp"
#include "../runtime/stdclass.hpp"
#include "../context.hpp"
#include <iostream>

Nodes::CallNode::CallNode(std::string method, AbstractNode *receiver, std::vector<AbstractNode*> arguments)
{
  this->method = method;
  this->receiver = receiver;
  this->arguments = arguments;
}

Runtime::Object*
Nodes::CallNode::eval(Context *context)
{
  if(receiver == NULL && arguments.empty() && context->hasLocal(method))
  {
    return context->getLocal(method);
  }

  Runtime::Object* evaledReceiver;
  if(receiver == NULL)
  {
    evaledReceiver = context->getCurrentSelf();
  }
  else
  {
    evaledReceiver = receiver->eval(context);
  }

  std::vector<Runtime::Object*> evalArguments;

  for(int i = 0; i < this->arguments.size(); i++)
  {
    Runtime::Object *evalArg = (this->arguments[i])->eval(context);
    evalArguments.push_back(evalArg);
  }

  //Runtime::Object *evalReciever = this->receiver->eval(context);
  return evaledReceiver->call(this->method, evalArguments);
}