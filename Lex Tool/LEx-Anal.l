digit	-?(([0-9]+)|([0-9]*\.[0-9]+))
letter	[a-zA-Z]
line 	\n 
quoted 	\"([^"])*\"
keyword	"int"|"main"|"if"|"for"|"else"|"return"|"printf"|"float"|"char"|"double"|"void"
%{
	int line_number = 1;  
	
%}
%%
#.* 					{printf("\n%s\t:\tPreprocessor\tline:%d\t",yytext,line_number);}

{digit}*				{printf("\n%s\t:\tNumber\tline:%d\t",yytext,line_number);}
{letter}+\(({letter}|{digit})*\)	{printf("\n%s\t:\tFunction\tline:%d\t",yytext,line_number);}
{keyword} 				{printf("\n%s\t:\tKeyword\tline:%d\t",yytext,line_number);}
{line} 					{ line_number++; } 	
("_")*{letter}("_"|{letter}|{digit})*	{ printf("\n%s\t:\tIdentifier\tline:%d\t",yytext,line_number);}
\(					{printf("\n%s\t:\tOpen-parantheses\tline:%d\t",yytext,line_number);}
\)					{printf("\n%s\t:\tClose-parantheses\tline:%d\t",yytext,line_number);}
\{					{printf("\n%s\t:\tBrace BLOCK BEGINS\tline:%d\t",yytext,line_number);}
\}					{printf("\n%s\t:\tBrace BLOCK ENDS\tline:%d\t",yytext,line_number);}
\;					{printf("\n%s\t:\tDelimiter\tline:%d\t",yytext,line_number);}
\/\/.*					{printf("\n%s\t:\tComment",yytext);}

\-|\+|\/|\*				{printf("\n%s\t:\tArithmetic Operator\tline:%d\t",yytext,line_number);}
\<|\>|\<=|\=>|\!=|\==			{printf("\n%s\t:\tRelational Operator\tline:%d\t",yytext,line_number);}
\=					{printf("\n%s\t:\tAssignment\tline:%d\t",yytext,line_number);}
\"					{printf("\n%s\t:\tDoublequotes\tline:%d\t",yytext,line_number);}
{quoted}				{printf("\n%s\t:\tQuoted string\t line:%d\t",yytext,line_number);}
%%
int main(){
	FILE *file;
	file = fopen("input.c","r");
	if(file){
		yyin = file;
		yylex();

	}
	else
		printf("\nNo input file");
	printf("\nScanned!\n");
	return 0;
}

