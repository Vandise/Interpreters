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
      Runtime::Object* value;
      LiteralNode(Runtime::Object* value);
      Runtime::Object* eval(Context *context);
  };
}

#endif