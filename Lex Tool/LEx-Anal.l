digit 	[0-9]*
letter	[a-zA-Z]
%%
"int"|"return"|"char"|"if"|"else"|"for"		{printf("\n%s is a keyword.",yytext);}
{digit}						{printf("\n%s is a number.",yytext);}
("_")*{letter}("_"|{letter}|{digit})*		{printf("\n%s is an identifier.",yytext);}
#.* 		{ printf("\n%s is a PREPROCESSOR DIRECTIVE",yytext);}
\/\/.* 		{ printf("\n%s is a comment",yytext);}
\( 		{ printf("\n%s is a open-Paranthesis",yytext);}
\)		{ printf("\n%s is a closing-Parantheses",yytext);}
"="|"-"|"+"|"/"|"<"	{ printf("\n%s is an operator",yytext);}
\{		{ printf("\n%s is a brace",yytext);}
\}		{ printf("\n%s is a brace",yytext);}
\[		{ printf("\n%s is bracket",yytext);}
\]		{ printf("\n%s is bracket",yytext);}
\;		{printf("\n%s is a delimiter",yytext);}
%%
int main(){
	
	FILE *file;
	file = fopen("input.c","r");
	if(!file)
	{	
		printf("could not open the file");
		exit(0);
	}		
	yyin = file;

	yylex();
	printf("\nScanned!");
	return 0;
}
