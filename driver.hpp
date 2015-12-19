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
  class AbstractNode;
}

namespace FrontEnd{

  class Driver{
    public:
      std::vector<Nodes::AbstractNode*> nodes;
      
    
       Driver() = default;
    
       virtual ~Driver();
    
       void parse( const char *filename );
      
    
       void add_upper();
       void add_lower();
       void add_word( const std::string &word );
       void add_class( const std::string &klass );
       void add_newline();
       void add_char();
       void add_int( int &number );
    
       std::ostream& print(std::ostream &stream);
    private:
       int chars      = 0;
       int words      = 0;
       int lines      = 0;
       int uppercase  = 0;
       int lowercase  = 0;
       FrontEnd::Parser  *parser  = nullptr;
       FrontEnd::Scanner *scanner = nullptr;
    };

}
#endif
