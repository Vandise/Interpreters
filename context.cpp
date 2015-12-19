#include "context.hpp"
#include "driver.hpp"
#include "runtime/stdclass.hpp"

Context::Context(Runtime::Object *currentSelf, Runtime::StdClass *currentClass, Context parent)
{
  
}

Context::Context(Runtime::Object *currentSelf, Runtime::StdClass *currentClass)
{
  
}

Context::Context(Runtime::Object *currentSelf)
{
  
}

Context::Context()
{
  
}

Runtime::Object*
Context::getCurrentSelf()
{
  
}

Runtime::StdClass*
Context::getCurrentClass()
{
  
}

Runtime::Object*
Context::getLocal(std::string name)
{
  
}

int
Context::hasLocal(std::string name)
{
  
}

void
Context::setLocal(std::string name, Runtime::Object *value)
{
  
}

Context*
Context::makeChildContext()
{
  
}

Runtime::Object*
Context::eval(FrontEnd::Driver driver)
{
  
}

Runtime::Object*
Context::eval(std::string code)
{
  
}