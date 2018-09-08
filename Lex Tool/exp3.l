%{
	#include "y.tab.h"
%}
%%
[a-zA-Z] {return ID;}
[0-9]+ {return NUMBER;}
[ \t] {;}
\n {return 0;}
. { return yytext[0];}
%%        