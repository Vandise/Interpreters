#include "runtime.hpp"

Runtime::StdClass*
Lang::Runtime::getObjectClass()
{
  return objectClass;
}

Runtime::Object*
Lang::Runtime::getMainObject()
{
  return mainObject;
}

Runtime::StdClass*
Lang::Runtime::getRootClass(std::string name)
{
  return static_cast<::Runtime::StdClass*>(objectClass->getConstant(name));
}

Runtime::StdClass*
Lang::Runtime::getExceptionClass()
{
  return getRootClass(std::string("Exception"));
}

Runtime::Object*
Lang::Runtime::getNil()
{
  return nilObject;
}

Runtime::Object*
Lang::Runtime::getTrue()
{
  return trueObject;
}

Runtime::Object*
Lang::Runtime::getFalse()
{
  return falseObject;
}

Runtime::Object*
Lang::Runtime::toBoolean(int value)
{
  return value ? getTrue() : getFalse();
}