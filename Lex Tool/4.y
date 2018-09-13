%{
	#include <stdio.h>
    int yylex();
    int yyerror();
%}
%token 	LETTER DIGIT 

%%
stmt: var 
    ;
var : LETTER  alpha_num
    | LETTER
    ;
alpha_num: LETTER alpha_num
        | DIGIT alpha_num
        |LETTER
        |DIGIT
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
