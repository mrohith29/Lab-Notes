%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%

[0-9]+          {yylval.a_number =atoi(yytext); return number;}
[-+*/();]       {return yytext[0];}
[ \t\n]         {;}
.               {ECHO; yyerror("unexpected character");}
%%
int yywrap(void){ return 0;}                      

