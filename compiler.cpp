#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

#include "driver.hpp"
#include "compiler/stack.hpp"
#include "bootstrapper.hpp"

using namespace std;

void print_vector(vector< vector< boost::variant<int, byte, char const*> > > vector);

int
main( const int argc, const char **argv )
{
  // sizes of the three tables
  int sizes[3];
  //
  //  Compiled Stack
  //    0     -   Instructions
  //    1     -   Literal Table
  //    2     -   Locals  Table
  //
  vector< vector< boost::variant<int, byte, char const*> > > compiled_stack;

  for(int i = 0; i < 3; i++)
  {
    compiled_stack.push_back(vector< boost::variant<int, byte, char const*> >());
  }

  //
  // Mock Stack
  //

  Table::instructions.push_back(0);
  Table::instructions.push_back(1);

  Table::literal.push_back(30);
  Table::literal.push_back("cString");

  compiled_stack[0] = Table::instructions;
  compiled_stack[1] = Table::literal;
  compiled_stack[2] = vector< boost::variant<int, byte, char const*> >();

  print_vector(compiled_stack);

  for(int i = 0; i < 3; i++)
  {
    sizes[i] = compiled_stack[i].size();
  }
  //
  // Compile to Binary
  //
  ofstream files;
  files.open("compiled/compiled.data", ios::out | ios::trunc | ios::binary);
  files.write((char*)&sizes, sizeof(sizes));
  files.close();
  files.open("compiled/compiled.data", ios::out | ios::app | ios::binary);
  for(size_t i = 0; i < compiled_stack.size(); i++)
  {
    files.write((char*)&compiled_stack[i][0], compiled_stack[i].size()*sizeof(boost::variant<int, byte, char const*>));
  }
  files.close();

  //
  // Parse Compiled File
  //
  int size_file[3];
  boost::variant<int, byte, char const*> temp;
  vector< vector< boost::variant<int, byte, char const*> > > compiled_stack_file;

  // open file
  ifstream filel;
	filel.open("compiled/compiled.data", ios::in | ios::binary);
	filel.read((char*)&size_file, sizeof(size_file));

  for(int i = 0; i < 3; i++)
  {
    compiled_stack_file.push_back(vector< boost::variant<int, byte, char const*> >());
    for(int j = 0; j < size_file[i]; j++)
    {
      filel.read((char*)&temp, sizeof(boost::variant<int, byte, char const*>));
      compiled_stack_file[i].push_back(temp);
    }
  }

  print_vector(compiled_stack_file);

  return( EXIT_SUCCESS );

}

void print_vector(vector< vector< boost::variant<int, byte, char const*> > > vector)
{
  for(int i = 0; i < vector.size(); i++)
  {
    cout << "Printing Vector: " << i << "\n";
    for(int j = 0; j < vector[i].size(); j++)
    {
      cout << "Vector Element: [" << j << "]" << vector[i][j] << "\n";
    }
  }
}
