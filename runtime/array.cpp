#include "array.hpp"
#include "../context.hpp"
#include "../runtime.hpp"
#include "../nodes/abstractnode.hpp"
#include <iostream>

Runtime::ArrayObject::ArrayObject(std::vector<Runtime::Object*> elements, Context *context)
{
  this->klass = Lang::Runtime::getRootClass(std::string("Array"));
  this->elements = elements;
  this->size = elements.size();
  this->context = context;
}