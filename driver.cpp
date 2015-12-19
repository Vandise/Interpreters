#include <cctype>
#include <fstream>
#include <cassert>

#include "driver.hpp"
#include "nodes/nodes.hpp"
#include "nodes/literalnode.hpp"
#include "nodes/callnode.hpp"

FrontEnd::Driver::~Driver()
{ 
   delete(scanner);
   scanner = nullptr;
   delete(parser);
   parser = nullptr;
}

void
FrontEnd::Driver::set_stack(std::vector<Nodes::AbstractNode*> stack)
{
  this->nodes = stack;
}

void 
FrontEnd::Driver::parse( const char * const filename )
{
   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() ) exit( EXIT_FAILURE );
   
   delete(scanner);
   try
   {
      scanner = new FrontEnd::Scanner( &in_file );
   }
   catch( std::bad_alloc &ba )
   {
      std::cerr << "Failed to allocate scanner: (" <<
         ba.what() << "), exiting!!\n";
      exit( EXIT_FAILURE );
   }
   
   delete(parser); 
   try
   {
      parser = new FrontEnd::Parser( (*scanner) /* scanner */, 
                                  (*this) /* driver */ );
   }
   catch( std::bad_alloc &ba )
   {
      std::cerr << "Failed to allocate parser: (" << 
         ba.what() << "), exiting!!\n";
      exit( EXIT_FAILURE );
   }

   parser->parse();
}

Runtime::Object*
FrontEnd::Driver::execute(Context *context)
{
  Nodes::Nodes *nodes = new Nodes::Nodes(this->nodes);
  return nodes->eval(context);
}
