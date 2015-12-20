#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__ 1

#include <string>
#include <cstdint>
#include <vector>
#include "scanner.hpp"
#include "parser.tab.hh"
#include "runtime/valueobject.hpp"

namespace Nodes
{
  class Nodes;
  class AbstractNode;
}

namespace Runtime
{
  class Object;
}

class Context;

namespace FrontEnd{

  class Driver{
    public:
    
       Driver() = default;
    
       virtual ~Driver();
    
       void parse( const char *filename );      
       void set_stack(std::vector<Nodes::AbstractNode*> stack);
       void push_node(Nodes::AbstractNode *node);
       Runtime::Object* execute(Context *context);
    

    private:
       FrontEnd::Parser  *parser  = nullptr;
       FrontEnd::Scanner *scanner = nullptr;
    };

}
#endif
