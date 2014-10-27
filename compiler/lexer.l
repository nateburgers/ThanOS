%{
#include <string.h>
#include "syntax_tree.h"
#include "parser-yy.hpp"
#define SAVE_TOKEN yylval->string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval->token = t)
%}

%option reentrant stack noyywrap
%option bison-bridge

%%

[ \t\n] ;
"val" return TOKEN(TOKEN_VAL);
"let" return TOKEN(TOKEN_LET);
"fun" return TOKEN(TOKEN_FUN);
"->" return TOKEN(TOKEN_RIGHT_ARROW);
"in" return TOKEN(TOKEN_IN);
"=" return TOKEN(TOKEN_EQUALS);
"(" return TOKEN(TOKEN_LEFT_PARENTHESIS);
")" return TOKEN(TOKEN_RIGHT_PARENTHESIS);
[0-9]+  SAVE_TOKEN; return TOKEN_INTEGER;
[a-zA-Z_][a-zA-Z0-9_]* SAVE_TOKEN; return TOKEN_IDENTIFIER;
. SAVE_TOKEN; return TOKEN_INVALID;

%%
