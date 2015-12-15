#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__ 1

#include <string>

namespace Runtime
{
  
  class StdClass;
  
  class Object
  {
    private:
      StdClass *klass;

    public:
      Object(StdClass *klass);
      Object();
  };

  class StdClass : public Object
  {
    private:
      std::string name;
      Runtime::StdClass *superClass;

    public:
      StdClass(std::string name, StdClass *superClass);
  };

}

#endif