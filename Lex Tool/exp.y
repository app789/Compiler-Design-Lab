%{
	#include<stdio.h>
	int yylex();
	int yyerror();
%}
%token 	ID 	NUMBER
%left 	'+' 	'-'      %{left-associative%}
%left 	'*' 	'/'
%%
stmt: ID '=' expr ';'
    ;
expr: expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | NUMBER
    | ID
    ;
%%
int yyerror()
{
  	printf("invalid exp");
	return 0;
}
int main()
{
	printf("enter expr : \n");
	yyparse();
	printf("valid exp");
	return 0;
}
