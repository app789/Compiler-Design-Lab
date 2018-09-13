%{
	#include "y.tab.h"
%}
%%
[a-zA-Z][a-zA-Z_0-9]* 	{return ID;}
[0-9]+(\.[0-9]*)? 	{return NUMBER;}
[ \t] 			{;}
\n 			{return 0;}
. 			{ return yytext[0];}
%%        
