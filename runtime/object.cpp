#include "object.hpp"

Runtime::Object::Object(StdClass *klass)
{
  this->klass = klass;
}

Runtime::StdClass::StdClass( std::string name, StdClass *superClass )
{
  this->name = name;
  this->superClass = superClass;
}