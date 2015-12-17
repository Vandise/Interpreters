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
      std::map<std::string, Object*> instanceVariables;

    public:
      Object();
      Object(StdClass *klass);
      Object(std::string name);
      StdClass* getStdClass();
      void     setStdClass(StdClass *klass);
      Object*  getInstanceVariable(std::string name);
      int      hasInstanceVariable(std::string name);
      void     setInstanceVariable(std::string name, Object value);
      Object*  call(std::string method, std::map<std::string, Object>);
      Object*  call(std::string method);
      int      isTrue();
      int      isFalse();
      int      isNil();
  };

}

#endif