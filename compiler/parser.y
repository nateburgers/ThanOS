%{
#include <string>
#include "syntax_tree.h"
  extern int yylex(void);
  void yyerror(const char *message) {
  }
%}

%union {
  const ast::Value *value;
  const ast::Expression *expression;
  const ast::Integer *integer;
  const ast::Variable *variable;
  const ast::Let *let;
  const ast::Application *application;
  const ast::Abstraction *abstraction;
  std::string *string;
  int token;
}

%pure-parser
/* %lex-param { void *scanner } */
/* %parse-param { void *scanner } */

%token <string> TOKEN_INVALID
%token <string> TOKEN_IDENTIFIER TOKEN_INTEGER
%token <token> TOKEN_VAL TOKEN_LET TOKEN_FUN TOKEN_RIGHT_ARROW
%token <token> TOKEN_IN TOKEN_EQUALS TOKEN_LEFT_PARENTHESIS TOKEN_RIGHT_PARENTHESIS

%type <value> program
%type <value> definition

%type <value> value
%type <expression> expression
%type <integer> integer
%type <variable> variable
%type <let> let
%type <application> application
%type <abstraction> abstraction

%start program

%%

program
: definition { $$ = $1; }
;

definition
: value { $$ = $1; }
;

value
: TOKEN_VAL TOKEN_IDENTIFIER TOKEN_EQUALS expression { $$ = new const ast::Value(*$2,$4); }
;


expression
: integer { $$ = $1; }
| variable { $$ = $1; }
| let { $$ = $1; }
| abstraction { $$ = $1; }
| application { $$ = $1; }
| TOKEN_LEFT_PARENTHESIS expression TOKEN_RIGHT_PARENTHESIS { $$ = $2; }
;

integer
: TOKEN_INTEGER { $$ = new const ast::Integer(5); }
;

variable
: TOKEN_IDENTIFIER { $$ = new const ast::Variable(*$1); }
;

let
: TOKEN_LET TOKEN_IDENTIFIER TOKEN_EQUALS expression TOKEN_IN expression
{ $$ = new const ast::Let(new const ast::Variable(*$2), $4, $6); }
;

abstraction
: TOKEN_FUN TOKEN_IDENTIFIER TOKEN_RIGHT_ARROW expression { $$ = new const ast::Abstraction(new const ast::Variable(*$2), $4); }
;


application
: expression expression { $$ = new const ast::Application($1, $2); }
;

%%
