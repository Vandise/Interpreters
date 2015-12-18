#include <iostream>
#include <cstdlib>

#include "driver.hpp"

#include "runtime.hpp"
#include "runtime/stdclass.hpp"

int 
main( const int argc, const char **argv )
{

   Runtime::StdClass *objectClass = new Runtime::StdClass(std::string("Object"));

   std::cout << "Here "+objectClass->getName();
   
   if(argc != 2 ) 
      return ( EXIT_FAILURE );
   FrontEnd::Driver driver;
   driver.parse( argv[1] );
   
   std::cout << "Results\n";
   
   driver.print(std::cout) << "\n";

   
   return( EXIT_SUCCESS );
}
