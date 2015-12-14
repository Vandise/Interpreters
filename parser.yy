%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {FrontEnd}
%define parser_class_name {Parser}

%code requires{
   namespace FrontEnd {
      class Driver;
      class Scanner;
   }
}

%parse-param { Scanner  &scanner  }
%parse-param { Driver  &driver  }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
   #include "driver.hpp"

#undef yylex
#define yylex scanner.yylex
}

/* token types */
%union {
   std::string *sval;
   int          ival;
}

%token            CLASS
%token            FUNC
%token            IF
%token            ELSE
%token            WHILE
%token            END
%token            SELF
%token            NIL
%token            TRUE
%token            FALSE
%token   <ival>   INTEGER
%token            FLOAT
%token            STRING
%token            IDENTIFIER
%token            CONSTANT

%token   <sval>   SEMICOLON
%token   <sval>   COLON
%token   <sval>   DOT
%token   <sval>   OPEN_PARENT
%token   <sval>   CLOSE_PARENT
%token   <sval>   AT
%token   <sval>   EQ
%token   <sval>   LE
%token   <sval>   GE
%token   <sval>   LT
%token   <sval>   GT
%token   <sval>   PLUS
%token   <sval>   MINUS
%token   <sval>   MUL
%token   <sval>   DIV
%token   <sval>   MOD
%token   <sval>   AND
%token   <sval>   OR
%token   <sval>   NOT
%token   <sval>   ASSIGN
%token   <sval>   COMMENT

/* %token   <sval>   NEWLINE */
%token   <sval>   WHITESPACE

%token            UPPER
%token            LOWER
%token   <sval>   WORD
%token            NEWLINE
%token            CHAR


/* destructor rule for <sval> objects */
%destructor { if ($$)  { delete ($$); ($$) = nullptr; } } <sval>


%%

list
  : item
  | list item
  ;

item
  : INTEGER { driver.add_int( $1 ); }
  | UPPER   { driver.add_upper(); }
  | LOWER   { driver.add_lower(); }
  | WORD    { driver.add_word( *$1 ); }
  | NEWLINE { driver.add_newline(); }
  | CHAR    { driver.add_char(); }
  ;

%%


void 
FrontEnd::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n"; 
}
