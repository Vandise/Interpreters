#ifndef __RUNTIME_HPP__
#define __RUNTIME_HPP__ 1

#include <string>
#include "runtime/object.hpp"
#include "runtime/stdclass.hpp"

namespace Runtime
{
  class Object;
  class StdClass;
}

namespace Lang
{
  class Runtime
  {
    public:
      static ::Runtime::StdClass *objectClass;
      static ::Runtime::Object   *mainObject;
      static ::Runtime::Object   *nilObject;
      static ::Runtime::Object   *trueObject;
      static ::Runtime::Object   *falseObject;
      
      static ::Runtime::StdClass *getObjectClass()
      {
        return objectClass;
      }

      static ::Runtime::Object*   getMainObject()
      {
        return mainObject;
      }

      static ::Runtime::StdClass* getRootClass(std::string name)
      {
        return static_cast<::Runtime::StdClass*>(objectClass->getConstant(name));
      }
      
      static ::Runtime::StdClass* getExceptionClass()
      {
        return getRootClass(std::string("Exception"));
      }
      
      static ::Runtime::Object*   getNil()
      {
        return nilObject;
      }
      
      static ::Runtime::Object*   getTrue()
      {
        return trueObject;
      }

      static ::Runtime::Object*   getFalse()
      {
        return falseObject;
      }

      static ::Runtime::Object*   toBoolean(int value)
      {
        return value ? getTrue() : getFalse();
      }
  };
}

#endif