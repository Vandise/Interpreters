#ifndef __RUNTIME_HPP__
#define __RUNTIME_HPP__ 1

#include <string>

namespace Lang
{
  class Lang;  
}

namespace Runtime
{
  class Object;
  class StdClass;
}

#include "runtime/object.hpp"
#include "runtime/stdclass.hpp"
#include "runtime/valueobject.hpp"

namespace Lang
{
  class Runtime
  {
    public:
      static ::Runtime::StdClass* objectClass;
      static ::Runtime::Object*   mainObject;
      static ::Runtime::Object*   nilObject;
      static ::Runtime::Object*   trueObject;
      static ::Runtime::Object*   falseObject;
      
      ::Runtime::StdClass*
      getObjectClass()
      {
        return objectClass;
      }
      
      ::Runtime::Object*
      getMainObject()
      {
        return mainObject;
      }
      
      ::Runtime::StdClass*
      getRootClass(std::string name)
      {
        return static_cast<::Runtime::StdClass*>(objectClass->getConstant(name));
      }
      
      ::Runtime::StdClass*
      getExceptionClass()
      {
        return getRootClass(std::string("Exception"));
      }
      
      ::Runtime::Object*
      getNil()
      {
        return nilObject;
      }
      
      ::Runtime::Object*
      getTrue()
      {
        return trueObject;
      }
      
      ::Runtime::Object*
      getFalse()
      {
        return falseObject;
      }
      
      ::Runtime::Object*
      toBoolean(int value)
      {
        return value ? getTrue() : getFalse();
      }
  };
  
}

#endif

Runtime::Object* Lang::Runtime::nilObject;