#ifndef __SYMBOLTABLE_HPP__
#define __SYMBOLTABLE_HPP__ 1

#include <vector>
#include <boost/variant.hpp>

typedef unsigned char byte;

class Table
{
  public:
    static std::vector< std::vector< boost::variant<int, byte, char const*> > > stack;
    static std::vector< boost::variant<int, byte, char const*> >                instructions;
    static std::vector< boost::variant<int, byte, char const*> >                literal;
    static std::vector< boost::variant<int, byte, char const*> >                locals;
};

#endif

std::vector< std::vector< boost::variant<int, byte, char const*> > > Table::stack;
std::vector< boost::variant<int, byte, char const*> >                Table::instructions;
std::vector< boost::variant<int, byte, char const*> >                Table::literal;
std::vector< boost::variant<int, byte, char const*> >                Table::locals;