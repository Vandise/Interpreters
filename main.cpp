#include <iostream>
#include <cstdlib>
#include <map>

#include "driver.hpp"
#include "bootstrapper.hpp"

int
main( const int argc, const char **argv )
{
   if(argc != 2 )
      return ( EXIT_FAILURE );

   Bootstrapper::run()->eval(argv[1]);

   return( EXIT_SUCCESS );
}
