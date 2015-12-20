%skeleton "lalr1.cc"
%require  "3.0"
%defines 
%define api.namespace {FrontEnd}
%define parser_class_name {Parser}
%define parse.trace

%code requires{

   namespace FrontEnd {
      class Driver;
      class Scanner;
   }
   
   namespace Nodes
   {
     class AbstractNode;
     class LiteralNode;
     class CallNode;
   }
   
   namespace Runtime
   {
     class ValueObject;
   }
   
}

%parse-param { Scanner  &scanner  }
%parse-param { Driver  &driver  }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   #include <map>

   /* include for all driver functions */
   #include "driver.hpp"

   #include "nodes/abstractnode.hpp"
   #include "nodes/nodes.hpp"
   #include "nodes/literalnode.hpp"
   #include "nodes/callnode.hpp"

   #undef yylex
   #define yylex scanner.yylex
   
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

%token   <sval>   NEWLINE 


/* destructor rule for <sval> objects */
%destructor { if ($$)  { delete ($$); ($$) = nullptr; } } <sval>

%left  "."
%right "!"
%left  "*" "/"
%left  "+" "-"
%left  ">" ">=" "<" "<="
%left  "==" "!="
%left  "&&"
%left  "||"
%right "="
%left  ","

/* token types */
%union {
   std::string                        *sval;
   int                                 ival;
   Nodes::LiteralNode                 *lit_node;
   Nodes::AbstractNode                *abs_node;
   std::vector<Nodes::AbstractNode *> *expressions;
   FrontEnd::Driver                   *driver;
}


%type <abs_node>     Expression Literal Operator
%type <driver>       Expressions

%%

Expressions: 
    Expression                            { 
                                            std::vector<Nodes::AbstractNode *> nodes;
                                            nodes.push_back($1);
                                            driver.set_stack(nodes);
                                            $$ = &driver;
                                          }
  | Expressions Terminator Expression     {
                                            std::cout << "Expressions terminator expression found \n";
                                            $1->push_node($3);
                                            $$ = &driver;
                                          }
  |                                       { /* do nothing */ }
  | Expressions Terminator                {

                                          }
  ;

Terminator: 
  NEWLINE
  | SEMICOLON
  ;

Expression:
  Literal
  | Operator
  ;

Literal:
  INTEGER                { $$ = new Nodes::LiteralNode(new Runtime::ValueObject($1)); }
  ;

Operator:
    Expression PLUS Expression        {
                                        std::map<int, Nodes::AbstractNode*> arguments;
                                        arguments[0] = $3;
                                        std::string method = *$2;
                                        $$ = new Nodes::CallNode(method, $1, arguments); 
                                      }

  | Expression MINUS Expression       {
                                        std::map<int, Nodes::AbstractNode*> arguments;
                                        arguments[0] = $3;
                                        std::string method = *$2;
                                        $$ = new Nodes::CallNode(method, $1, arguments); 
                                      }
  ;


%%


void 
FrontEnd::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n"; 
}
