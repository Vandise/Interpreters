%{

#include <algorithm>
#include <string>
#include <iostream>
#include "scanner.hpp"


typedef FrontEnd::Parser::token token;
bool term = false;

#define STOKEN( x ) ( new std::string( x ) )

#define STRIP_QUOTES( s ) ( s->erase(remove(s->begin(), s->end(), '\"' ), s->end()) )

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

\"[^"]*\"   {
              yylval->sval = STOKEN(yytext);
              yylval->sval->erase(remove(yylval->sval->begin(), yylval->sval->end(), '\"' ), yylval->sval->end());
              return(token::STRING);
            }
\n          { 
               return( token::NEWLINE );   
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
"do"        { return(token::DO); }

([A-Z][a-zA-Z]*)+ {
                    yylval->sval = STOKEN(yytext);
                    return( token::CONSTANT );     
                  }

[_a-zA-Z\\?\\!]+  {
                    yylval->sval = STOKEN(yytext);
                    return( token::IDENTIFIER );
                  }

"|"         { return(token::PIPE); }

"->"        { return(token::LAMBDA); }

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
              return( token::OPEN_PAREN );
            }

")"         {
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
"="         {
              yylval->sval = STOKEN(yytext);
              return( token::ASSIGN );
            }

"@"         { return(token::AT); }
            
","         { yylval->sval = STOKEN(yytext); return( token::COMMA ); }

"."         { return( token::DOT ); }

":"         { return( token::COLON ); }

"["         { return( token::L_BRACKET ); }
"]"         { return( token::R_BRACKET ); }

.           {  /* printf("unknown character in input: %c\n", *yytext); */ }

%%


