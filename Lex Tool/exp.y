%{
	#include<stdio.h>
%}
%token 	ID 		NUMBER
%left 	'+' 	'-'
%left 	'*' 	'/'
%%
stmt:expr
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
void yyerror()
{
  printf("invalid exp");
}
int main()
{
	printf("enter expr : \n");
	yyparse();
	printf("valid exp");
	return 0;
}
