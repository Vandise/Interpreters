#ifndef __SELFNODE_HPP__
#define __SELFNODE_HPP__ 1

#include "abstractnode.hpp"

namespace Nodes
{
  class SelfNode : public AbstractNode
  {
    Runtime::Object* eval(Context *context);
  };
}

#endif