#include "valueobject.hpp"

/*

  ValueObject - Primitive Datatype Storage
    Object for storing primitive datatypes and assigning a parent class

*/
Runtime::ValueObject::ValueObject(Runtime::StdClass *klass, boost::variant<int,std::string> value)
/* TODO: Call Super after runtime is initialized -- : super(i), J(j) etc */
{
  this->value = value;
}

/*

  Constructor - String Type
    Sets the primitive datatype to String -- super("String")

*/
Runtime::ValueObject::ValueObject(std::string value)
/* TODO: Call Super after runtime is initialized -- : super(i), J(j) etc */
{
  this->value = value;
}

/*

  Constructor - Int Type
    Sets the primitive datatype to int -- super("Integer")

*/
Runtime::ValueObject::ValueObject(int value)
/* TODO: Call Super after runtime is initialized -- : super(i), J(j) etc */
{
  this->value = value;
}

/*

  Constructor - Float Type
    Sets the primitive datatype to float -- super("float")

*/
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

/*

  getValue()
    Returns the primitive (native) DataType in C++

*/
boost::variant<int,std::string>
Runtime::ValueObject::getValue()
{
  return this->value;
}