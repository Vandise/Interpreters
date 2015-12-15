#include <cctype>
#include <fstream>
#include <cassert>

#include "driver.hpp"
#include "nodes/literalnode.hpp"

FrontEnd::Driver::~Driver()
{ 
   delete(scanner);
   scanner = nullptr;
   delete(parser);
   parser = nullptr;
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
FrontEnd::Driver::add_upper()
{ 
   uppercase++; 
   chars++; 
   words++; 
}

void 
FrontEnd::Driver::add_lower()
{ 
   lowercase++; 
   chars++; 
   words++; 
}

void 
FrontEnd::Driver::add_word( const std::string &word )
{
   std::cout << word;
   words++; 
   chars += word.length();
   for(const char &c : word ){
      if( islower( c ) )
      { 
         lowercase++; 
      }
      else if ( isupper( c ) ) 
      { 
         uppercase++; 
      }
   }
}

void
FrontEnd::Driver::add_int( int &number )
{
  Nodes::LiteralNode *node = new Nodes::LiteralNode(number);
  std::cout << node->value;
}

void
FrontEnd::Driver::add_class( const std::string &klass )
{
  std::cout << klass;
  words++;
}

void 
FrontEnd::Driver::add_newline()
{ 
   lines++; 
   chars++; 
}

void 
FrontEnd::Driver::add_char()
{ 
   chars++; 
}


std::ostream& 
FrontEnd::Driver::print( std::ostream &stream )
{
   stream << "Uppercase: " << uppercase << "\n";
   stream << "Lowercase: " << lowercase << "\n";
   stream << "Lines: " << lines << "\n";
   stream << "Words: " << words << "\n";
   stream << "Characters: " << chars << "\n";
   return(stream);
}
