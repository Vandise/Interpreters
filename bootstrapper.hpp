#ifndef __BOOTSTRAPPER_HPP__
#define __BOOTSTRAPPER_HPP__ 1

#include "runtime.hpp"
#include "context.hpp"

class Context;

class Bootstrapper
{
  public:
    static Context* run();
};

#endif