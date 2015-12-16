#include "object.hpp"


Runtime::Object::Object()
{
  /* TODO */
}

Runtime::Object::Object(Runtime::StdClass *klass)
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
Runtime::Object::Object(std::string name)
{
  /* TODO */
}

Runtime::StdClass*
Runtime::Object::getStdClass()
{
  /* TODO */
}

void
Runtime::Object::setStdClass(Runtime::StdClass *klass)
{
  /* TODO */
}

Runtime::Object
Runtime::Object::getInstanceVariable(std::string name)
{
  /* TODO */
}

int
Runtime::Object::hasInstanceVariable(std::string name)
{
  /* TODO - this should return a boolean type */
}

void
Runtime::Object::setInstanceVariable(std::string name, Runtime::Object value)
{
  /* TODO */
}

Runtime::Object
Runtime::Object::call(std::string method, std::map<std::string, Runtime::Object>)
{
  /* TODO */
}

Runtime::Object
Runtime::Object::call(std::string method)
{
  /* TODO */
}

int
Runtime::Object::isTrue()
{
  /* TODO */
}

int
Runtime::Object::isFalse()
{
  /* TODO */
}

int
Runtime::Object::isNil()
{
  /* TODO */
}