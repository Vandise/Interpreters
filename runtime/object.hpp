#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__ 1

#include <string>
#include <map>

namespace Runtime
{
  
  class StdClass;
  
  class Object
  {
    private:
      typedef Object super;
      StdClass *klass;
      std::map<std::string, Object> instanceVariables;

    public:
      Object(StdClass *klass);
      Object(std::string name);
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