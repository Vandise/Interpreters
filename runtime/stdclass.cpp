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
  return name;
}

void
Runtime::StdClass::setConstant(std::string name, Runtime::Object *value)
{
  constants[name] = value;
}

Runtime::StdClass*
Runtime::StdClass::getSuperClass()
{
  return superClass;
}

Runtime::Object*
Runtime::StdClass::getConstant(std::string name)
{
  if(constants.count(name) >= 1)
    return constants[name];
  if(superClass)
    return superClass->getConstant(name);
  return Lang::Runtime::getNil();
}

int
Runtime::StdClass::hasConstant(std::string name)
{
  if(constants.count(name) >= 1)
    return 1;
  if(superClass)
    return superClass->hasConstant(name);
  return 0;
}

void
Runtime::StdClass::lookup(std::string name)
{
  /* TODO - methods */
}

int
Runtime::StdClass::hasMethod(std::string name)
{
  /* TODO - methods  */
}

void
Runtime::StdClass::addMethod(std::string name, std::string method)
{
  /* TODO - methods */
}

Runtime::Object*
Runtime::StdClass::newInstance(std::string value)
{
  return new Runtime::Object(this);
}

Runtime::StdClass*
Runtime::StdClass::newSubclass(std::string name)
{
  Runtime::StdClass *klass = new Runtime::StdClass(name, this);
  Lang::Runtime::getObjectClass()->setConstant(name, klass);
  return klass;
}

Runtime::StdClass*
Runtime::StdClass::subclass(std::string name)
{
  Runtime::StdClass *objClass = Lang::Runtime::getObjectClass();
  if(objClass->hasConstant(name))
    return static_cast<Runtime::StdClass*>(objClass->getConstant(name));
  return newSubclass(name);
}

int
Runtime::StdClass::isSubclass(Runtime::StdClass *klass)
{
  if(klass == this)                  return 1;
  if(klass->getSuperClass() == 0)    return 0;
  if(klass->getSuperClass() == this) return 1;
  return isSubclass(klass->getSuperClass());
}

int
Runtime::StdClass::equals(std::string other)
{
  /* TODO */
}