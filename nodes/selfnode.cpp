#include "selfnode.hpp"
#include "../context.hpp"

Runtime::Object*
Nodes::SelfNode::eval(Context *context)
{
  return context->getCurrentSelf();
}