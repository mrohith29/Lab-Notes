%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
%}

%%

[0-9]+(\.[0-9]+)? {
    yylval.dval = atof(yytext);
    return DIGIT;
}

[+\-*/()\n] {
    return yytext[0];
}

[ \t] ;  // ignore whitespace

. {
    printf("Unknown character: %s\n", yytext);
}

%%

int yywrap() {
    return 1;
}
