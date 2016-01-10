#ifndef __ARRAYOBJECT_HPP__
#define __ARRAYOBJECT_HPP__ 1

#include "object.hpp"
#include <string>
#include <vector>

class Context;

namespace Runtime
{
  class Object;
  class StdClass;
  
  class ArrayObject : public Object
  {
    private:
      Context *context;
    public:
      int size;
      std::vector<Runtime::Object*> elements;
      ArrayObject(std::vector<Runtime::Object*> elements, Context *context);
  };
}

#endif