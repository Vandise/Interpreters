#ifndef __LITERALNODE_HPP__
#define __LITERALNODE_HPP__ 1

#include <boost/variant.hpp>
#include "abstractnode.hpp"
#include "../runtime/valueobject.hpp"

/*

  TODO:
    Initialize Runtime - Bind each value type for literals
    to one of the Runtimes objectClass subclasses

*/

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
      void eval();
  };
}

#endif