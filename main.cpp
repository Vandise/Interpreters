#include <iostream>
#include <cstdlib>
#include <map>

#include "driver.hpp"
#include "bootstrapper.hpp"

int 
main( const int argc, const char **argv )
{
  Bootstrapper::run();

   if(argc != 2 ) 
      return ( EXIT_FAILURE );
   FrontEnd::Driver driver;
   driver.parse( argv[1] );
   
   std::cout << "Results\n";
   
   driver.print(std::cout) << "\n";

   
   return( EXIT_SUCCESS );
}
