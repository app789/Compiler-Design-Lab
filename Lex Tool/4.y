%{
	#include<stdio.h>
%}
%token 	LETTER DIGIT

%%
stmt: var
    ;
var : LETTER  alpha_num
    | 
    ;
alpha_num: LETTER alpha_num
        | DIGIT alpha_num
        |LETTER
        |DIGIT
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
