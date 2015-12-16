#include "valueobject.hpp"

Runtime::ValueObject::ValueObject(Runtime::StdClass *klass, boost::variant<int,std::string> value)
/* TODO: Call Super after runtime is initialized -- : super(i), J(j) etc */
{
  this->value = value;
}

Runtime::ValueObject::ValueObject(std::string value)
/* TODO: Call Super after runtime is initialized -- : super(i), J(j) etc */
{
  this->value = value;
}

Runtime::ValueObject::ValueObject(int value)
/* TODO: Call Super after runtime is initialized -- : super(i), J(j) etc */
{
  this->value = value;
}

Runtime::ValueObject::ValueObject(float value)
/* TODO: Call Super after runtime is initialized -- : super(i), J(j) etc */
{
  this->value = value;
}

int
Runtime::ValueObject::isFalse()
{
  /* TODO */
}

int
Runtime::ValueObject::isNil()
{
  /* TODO */
}

boost::variant<int,std::string>
Runtime::ValueObject::getValue()
{
  /* TODO */
}