%{

#include <string>
#include <iostream>
#include "scanner.hpp"


typedef FrontEnd::Parser::token token;
bool term = false;

#define STOKEN( x ) ( new std::string( x ) )
#define yyterminate() return (term = !term)?Parser::token::PRGEND : YY_NULL

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

%}

%option debug 
%option nodefault 
%option yyclass="FrontEnd::Scanner" 
%option noyywrap 
%option c++

comment               \#.*$

%%

[\ \t]+

"//".*      { /* DO NOTHING */ }

[0-9]+      {
              yylval->ival = (atoi(yytext));
              return( token::INTEGER );
            }
            
"end"       { return(token::END);   }
"func"      { return(token::FUNC);  }
"class"     { return(token::CLASS); }
"if"        { return(token::IF);    }
"else"      { return(token::ELSE);  }
"while"     { return(token::WHILE); }
"true"      { return(token::TRUE);  }
"false"     { return(token::FALSE); }
"nil"       { return(token::NIL);   }
"self"      { return(token::SELF);  }

"+"         {
              yylval->sval = STOKEN(yytext);
              return( token::PLUS );
            }

"-"         {
              yylval->sval = STOKEN(yytext);
              return( token::MINUS );
            }

"*"         {
              yylval->sval = STOKEN(yytext);
              return( token::MUL );
            }

"/"         {
              yylval->sval = STOKEN(yytext);
              return( token::DIV );
            }
            
"("         {
              yylval->sval = STOKEN(yytext);
              return( token::OPEN_PAREN );
            }

")"         {
              yylval->sval = STOKEN(yytext);
              return( token::CLOSE_PAREN );
            }           
            
"<"         {
              yylval->sval = STOKEN(yytext);
              return( token::LT );
            }
">"         {
              yylval->sval = STOKEN(yytext);
              return( token::GT );
            }

\n          { 
               return( token::NEWLINE );   
            }

.           {  printf("unknown character in input: %c\n", *yytext); }

%%


