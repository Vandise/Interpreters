%skeleton "lalr1.cc"
%require  "3.0"
%defines 
%define api.namespace {FrontEnd}
%define parser_class_name {Parser}
%define parse.trace

%code requires{
#include <vector>
  namespace FrontEnd {
    class Driver;
    class Scanner;
  }
  
  namespace Nodes
  {
   class Nodes;
   class AbstractNode;
   class LiteralNode;
   class CallNode;
   class MethodDefinitionNode;
  }
  
  namespace Runtime
  {
   class ValueObject;
  }
  
  namespace Lang
  {
   class Runtime;
  }
  
  class NodeStack;
}

%parse-param { Scanner  &scanner  }
%parse-param { Driver  &driver  }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   #include <map>
   #include <vector>

   /* include for all driver functions */
   #include "driver.hpp"

   #include "nodes/abstractnode.hpp"
   #include "nodes/nodes.hpp"
   #include "nodes/literalnode.hpp"
   #include "nodes/callnode.hpp"
   #include "nodes/selfnode.hpp"
   #include "nodes/localassignnode.hpp"
   #include "nodes/methoddefinitionnode.hpp"
   #include "nodes/classdefinitionnode.hpp"
   #include "nodes/constantnode.hpp"
   #include "nodes/instancevariablenode.hpp"
   #include "nodes/instancevariableassign.hpp"
   #include "nodes/lambdanode.hpp"
   #include "nodes/arraynode.hpp"
   #include "runtime.hpp"

   #undef yylex
   #define yylex scanner.yylex
   
}

%token            CLASS
%token            FUNC
%token            IF
%token            ELSE
%token            WHILE
%token            END
%token            DO
%token            SELF
%token            NIL
%token            TRUE
%token            FALSE
%token   <ival>   INTEGER
%token            FLOAT
%token   <sval>   STRING
%token   <sval>   IDENTIFIER
%token   <sval>   CONSTANT

%token   <sval>   SEMICOLON
%token            COLON
%token            DOT
%token            OPEN_PAREN
%token            CLOSE_PAREN
%token            L_BRACKET
%token            R_BRACKET
%token            PIPE
%token            LAMBDA
%token            AT
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
%token   <sval>   COMMA
%token   <sval>   NEWLINE 
%token            PRGEND 0     "end of file"


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
   Nodes::Nodes                       *nodes;
   std::vector<std::string>           *parameters;
   std::vector<Nodes::AbstractNode*>  *arguments;
}


%type <abs_node>     Expression Literal Call Operator SetLocal GetLocal Function Iterable Lambda Class GetConstant InstanceVariable
%type <driver>       Expressions
%type <nodes>        BodyExpressions
%type <parameters>   Parameters
%type <arguments>    Arguments

%%

Expressions: 
    Expression                            { 
                                            std::vector<Nodes::AbstractNode *> nodes;
                                            nodes.push_back($1);
                                            driver.set_stack(nodes);
                                            $$ = &driver;
                                          }
  | Expressions Terminator Expression     {
                                            $1->push_node($3);
                                            $$ = $1;
                                          }
  |                                       { /* do nothing */ }
  | Expressions Terminator                {
                                            $$ = $1;
                                          }
  ;

BodyExpressions: 
    Expression                            {
                                            std::vector<Nodes::AbstractNode *> nodes;
                                            nodes.push_back($1);
                                            Nodes::Nodes *nodelist = new Nodes::Nodes(nodes);
                                            $$ = nodelist;
                                          }
  | BodyExpressions Terminator Expression {
                                            $1->add($3);
                                            $$ = $1;
                                          }
  |                                       { /* do nothing */ }
  | BodyExpressions Terminator            {
                                            $$ = $1;
                                          }
  ;

Terminator: 
  NEWLINE
  | SEMICOLON
  ;

Expression:
  Literal
  | Call
  | Operator
  | GetConstant
  | InstanceVariable
  | SetLocal
  | GetLocal
  | Function
  | Lambda
  | Iterable
  | Class
  | OPEN_PAREN Expression CLOSE_PAREN     { $$ = $2; }
  ;

Literal:
    INTEGER                { $$ = new Nodes::LiteralNode(new Runtime::ValueObject($1)); }
  | STRING                 { $$ = new Nodes::LiteralNode(new Runtime::ValueObject(*$1)); }
  | TRUE                   { $$ = new Nodes::LiteralNode(Lang::Runtime::trueObject); }
  | FALSE                  { $$ = new Nodes::LiteralNode(Lang::Runtime::falseObject); }
  | NIL                    { $$ = new Nodes::LiteralNode(Lang::Runtime::nilObject); }
  | SELF                   { $$ = new Nodes::SelfNode(); }
  ;

Call:
    IDENTIFIER OPEN_PAREN Arguments CLOSE_PAREN                 { $$ = new Nodes::CallNode(*$1, NULL, *$3); }
  | Expression DOT IDENTIFIER OPEN_PAREN Arguments CLOSE_PAREN  { $$ = new Nodes::CallNode(*$3, $1, *$5);   }
  | Expression DOT IDENTIFIER                                   {
                                                                  std::vector<Nodes::AbstractNode*> *arguments = new std::vector<Nodes::AbstractNode*>();
                                                                  $$ = new Nodes::CallNode(*$3, $1, *arguments);
                                                                }
  | Expression DOT IDENTIFIER Arguments                         {
                                                                   $$ = new Nodes::CallNode(*$3, $1, *$4);
                                                                }
  | Expression L_BRACKET Expression R_BRACKET                   {
                                                                  std::vector<Nodes::AbstractNode*> *arguments = new std::vector<Nodes::AbstractNode*>();
                                                                  arguments->push_back($3);
                                                                  $$ = new Nodes::CallNode(std::string("index"),$1,*arguments);
                                                                }
  ;

Arguments:
    Expression                  {
                                  std::vector<Nodes::AbstractNode*> *arguments = new std::vector<Nodes::AbstractNode*>();
                                  arguments->push_back($1);
                                  $$ = arguments;
                                }
  | Arguments COMMA Expression  {
                                  $1->push_back($3);
                                  $$ = $1;
                                }
  |                             {
                                  std::vector<Nodes::AbstractNode*> *arguments = new std::vector<Nodes::AbstractNode*>();
                                  $$ = arguments;
                                }
  ;

Operator:
    Expression PLUS Expression        {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back($3);
                                        std::string method = *$2;
                                        $$ = new Nodes::CallNode(method, $1, arguments); 
                                      }

  | Expression MINUS Expression       {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back($3);
                                        std::string method = *$2;
                                        $$ = new Nodes::CallNode(method, $1, arguments); 
                                      }
  | Expression MUL Expression         {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back($3);
                                        std::string method = *$2;
                                        $$ = new Nodes::CallNode(method, $1, arguments); 
                                      }
  | Expression DIV Expression         {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back($3);
                                        std::string method = *$2;
                                        $$ = new Nodes::CallNode(method, $1, arguments); 
                                      }
  | Expression LT Expression          {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back($3);
                                        std::string method = *$2;
                                        $$ = new Nodes::CallNode(method, $1, arguments); 
                                      }
  | Expression GT Expression          {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back($3);
                                        std::string method = *$2;
                                        $$ = new Nodes::CallNode(method, $1, arguments); 
                                      }
  ;

SetLocal:
    IDENTIFIER ASSIGN Expression     { $$ = new Nodes::LocalAssignNode(*$1, $3); }
  | AT IDENTIFIER ASSIGN Expression  { $$ = new Nodes::InstanceVariableAssign(*$2, $4); }
  ;

GetLocal:
  IDENTIFIER           {
              // Evaluate "my_local" as a local variable 
              // since we cant have a function (with no arguments and called without parens) 
                          // and a variable named the same
                          std::vector<Nodes::AbstractNode*> arguments;
                          $$ = new Nodes::CallNode(*$1, NULL, arguments);
                       }
  ;

Function:
  FUNC IDENTIFIER OPEN_PAREN Parameters CLOSE_PAREN Terminator
    BodyExpressions
  END                             {
                                    $$ = new Nodes::MethodDefinitionNode(*$2, *$4, $7);
                                  }

  | FUNC IDENTIFIER Terminator
      BodyExpressions
    END                           {
                                    std::vector<std::string> arguments = std::vector<std::string>();
                                    $$ = new Nodes::MethodDefinitionNode(*$2, arguments, $4);
                                  }
  ;

Lambda:
    LAMBDA DO PIPE Parameters PIPE Terminator
      BodyExpressions
    END                           {
                                    $$ = new Nodes::LambdaNode(*$4,$7);
                                  }
  ;

Iterable:
    L_BRACKET Arguments R_BRACKET {
                                    $$ = new Nodes::ArrayNode(*$2);    
                                  }
  ;

Parameters:
    IDENTIFIER                    {
                                    std::vector<std::string> *parameters = new std::vector<std::string>();
                                    parameters->push_back(*$1);
                                    $$ = parameters;
                                  }
  |  Parameters COMMA IDENTIFIER  { $1->push_back(*$3); $$ = $1; }
  |                               { 
                                    std::vector<std::string> *parameters = new std::vector<std::string>();
                                    $$ = parameters;
                                  }
  ;

Class:
  CLASS CONSTANT COLON CONSTANT Terminator
    BodyExpressions
  END                             {
                                    $$ = new Nodes::ClassDefinitionNode(*$2, *$4, $6);
                                  }

  | CLASS CONSTANT Terminator
      BodyExpressions
    END                           {
                                    $$ = new Nodes::ClassDefinitionNode(*$2, std::string(""), $4);
                                  }
  ;

GetConstant:
    CONSTANT                      { $$ = new Nodes::ConstantNode(*$1); }
  ;

InstanceVariable:
    AT IDENTIFIER                 { $$ = new Nodes::InstanceVariableNode(*$2); }
  ;
%%


void 
FrontEnd::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n"; 
}
