#include "stdclass.hpp"
#include "../runtime.hpp"

Runtime::StdClass::StdClass(std::string name)
{
  construct(name);
}

Runtime::StdClass::StdClass(std::string name, Runtime::StdClass *superClass)
{
  this->name = name;
  this->superClass = superClass;
}

void
Runtime::StdClass::construct(std::string name)
{
  this->name = name;
  this->superClass = Lang::Runtime::getObjectClass();
}

std::string
Runtime::StdClass::getName()
{
  /* TODO */
}

void
Runtime::StdClass::setConstant(std::string name, Runtime::Object value)
{
  /* TODO */
}

Runtime::Object*
Runtime::StdClass::getConstant(std::string name)
{
  /* TODO */
}

int
Runtime::StdClass::hasConstant(std::string name)
{
  /* TODO */
}

void
Runtime::StdClass::lookup(std::string name)
{
  /* TODO */
}

int
Runtime::StdClass::hasMethod(std::string name)
{
  /* TODO */
}

void
Runtime::StdClass::addMethod(std::string name, std::string method)
{
  /* TODO */
}

Runtime::Object
Runtime::StdClass::newInstance(std::string value)
{
  /* TODO */
}

Runtime::StdClass
Runtime::StdClass::newSubclass(std::string name)
{
  /* TODO */
}

Runtime::StdClass
Runtime::StdClass::subclass(std::string name)
{
  /* TODO */
}

int
Runtime::StdClass::isSubclass(Runtime::StdClass *klass)
{
  /* TODO */
}

int
Runtime::StdClass::equals(std::string other)
{
  /* TODO */
}