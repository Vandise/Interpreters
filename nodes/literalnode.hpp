#ifndef __LITERALNODE_HPP__
#define __LITERALNODE_HPP__ 1

#include <boost/variant.hpp>
#include "abstractnode.hpp"

/*

  TODO:
    Initialize Runtime - Bind each value type for literals
    to one of the Runtimes objectClass subclasses

*/

namespace Nodes
{
  class LiteralNode : public AbstractNode
  {
    public:
      boost::variant<int> value;
      LiteralNode(int value);
      void eval();
  };
}

#endif