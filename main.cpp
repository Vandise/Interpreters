#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

#include "driver.hpp"
#include "bootstrapper.hpp"

int
main( const int argc, const char **argv )
{
  if(argc != 2 )
    return ( EXIT_FAILURE );

  if(std::string(argv[1]) == "-i")
  {
    std::string input;
    do
    {
      std::cout << "\n >> ";
      //std::cin >> input;
      std::getline(std::cin,input);
      std::ofstream out("interactive.src");
      out << input;
      out.close();
      std::cout << "=> ";
      std::cout << Bootstrapper::run()->eval("interactive.src")->getValue();
    } while(input != "exit");
    std::cout << "\nInteractive mode\n";
    return( EXIT_SUCCESS );
  }

  Bootstrapper::run()->eval(argv[1]);

  return( EXIT_SUCCESS );
}
