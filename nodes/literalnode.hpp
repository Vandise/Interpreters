#ifndef __LITERALNODE_HPP__
#define __LITERALNODE_HPP__ 1

#include <boost/variant.hpp>
#include "abstractnode.hpp"

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