#include "instancevariableassign.hpp"
#include "../runtime/stdclass.hpp"
#include "../context.hpp"

Nodes::InstanceVariableAssign::InstanceVariableAssign(std::string name, Nodes::AbstractNode *expression)
{
  this->name = name;
  this->expression = expression;
}

Runtime::Object*
Nodes::InstanceVariableAssign::eval(Context *context)
{
  Runtime::Object *value = this->expression->eval(context);
  context->getCurrentSelf()->setInstanceVariable(this->name, value);
  return value;
}