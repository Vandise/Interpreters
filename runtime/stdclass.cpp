#include "stdclass.hpp"

Runtime::StdClass::StdClass( std::string name, StdClass *superClass )
{
  this->name = name;
  this->superClass = superClass;
}