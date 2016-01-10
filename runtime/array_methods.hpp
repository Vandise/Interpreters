#ifndef __ARRAYMETHODS_HPP__
#define __ARRAYMETHODS_HPP__ 1

#include <iostream>
#include <string>
#include <stdexcept>
#include "method.hpp"
#include "../runtime.hpp"
#include "valueobject.hpp"
#include <boost/variant/get.hpp>
#include "array.hpp"

struct ArraySize : Method
{
  Runtime::Object* call(Runtime::Object *receiver, std::vector<Runtime::Object*> arguments)
  {
    Runtime::ArrayObject* arrayObject = (Runtime::ArrayObject*)receiver;
    return new Runtime::ValueObject(arrayObject->size);
  }
};

struct ArrayIndex : Method
{
  Runtime::Object* call(Runtime::Object *receiver, std::vector<Runtime::Object*> arguments)
  {
    Runtime::ArrayObject* arrayObject = (Runtime::ArrayObject*)receiver;
    
    if(arguments.size() > 1 || arguments.size() == 0)
    {
      throw std::invalid_argument("Array.index expects one parameter\n");
    }
    
    if(arguments[0]->getName().compare("Integer"))
    {
      throw std::invalid_argument("Array.index accepts only class Integer\n");
    }
    
    int index = boost::get<int>(arguments[0]->getValue());
    
    if((arrayObject->size - 1) < index)
    {
      throw std::out_of_range(std::string("Call to undefined index ") << index);
    }
    
    return arrayObject->elements.at(index);
  }
};

ArraySize   array_size_method;
ArrayIndex  array_index_method;

#endif