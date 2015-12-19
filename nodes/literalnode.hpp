#ifndef __LITERALNODE_HPP__
#define __LITERALNODE_HPP__ 1

#include <boost/variant.hpp>
#include "abstractnode.hpp"
#include "../runtime/valueobject.hpp"

class Context;

namespace Runtime
{
  class ValueObject;
}

namespace Nodes
{
  class LiteralNode : public AbstractNode
  {
    public:
      Runtime::ValueObject* value;
      LiteralNode(Runtime::ValueObject* value);
      Runtime::ValueObject* eval(Context *context);
  };
}

#endif