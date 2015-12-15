#include "object.hpp"

Runtime::Object::Object(StdClass *klass)
{
  this->klass = klass;
}

/*
  Not yet implemented, this is the "super()" method that will make
  the super class of a ValueObject. ie
  
  ValueObject(int value)
    super("Integer")
  
  Integer will be a subclass of Object and instantiated in the runtime.
  That way we can add methods to numbers and strings without creating different
  nodes other than the current literal node.
  
*/
Runtime::Object::Object( std::string name )
{
  /* todo */
}

Runtime::Object::Object( )
{
  /* leave blank, should be deleted after the runtime is set up */
}

Runtime::StdClass::StdClass( std::string name, StdClass *superClass )
{
  this->name = name;
  this->superClass = superClass;
}