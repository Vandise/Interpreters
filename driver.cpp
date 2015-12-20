#include <cctype>
#include <fstream>
#include <cassert>

#include "nodestack.hpp"
#include "driver.hpp"
#include "nodes/nodes.hpp"
#include "nodes/literalnode.hpp"
#include "nodes/callnode.hpp"
#include "context.hpp"

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
  NodeStack::stack = stack;
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

void
FrontEnd::Driver::push_node(Nodes::AbstractNode *node)
{
  NodeStack::stack.push_back(node);
}

Runtime::Object*
FrontEnd::Driver::execute(Context *context)
{
  Nodes::Nodes *node = new Nodes::Nodes(NodeStack::stack);
  return node->eval(context);
}
