%{

#include <string>
#include <iostream>
#include "scanner.hpp"


typedef FrontEnd::Parser::token token;


#define STOKEN( x ) ( new std::string( x ) )
/* #define yyterminate() return( token::END ) */

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

%}

%option debug 
%option nodefault 
%option yyclass="FrontEnd::Scanner" 
%option noyywrap 
%option c++

%%

[\ \t]+

\#.*$

[0-9]+      {
              yylval->ival = (atoi(yytext));
              return( token::INTEGER );
            }

"+"         {
              yylval->sval = STOKEN(yytext);
              return( token::PLUS );
            }

\n          { 
               return( token::NEWLINE );   
            }


%%


