%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int op = 0;
float a = 0, b = 0;

void digi();  // Forward declaration
%}

%%
[0-9]+(\.[0-9]+)?    { digi(); }
"+"                 { op = 1; }
"-"                 { op = 2; }
"*"                 { op = 3; }
"/"                 { op = 4; }
"^"                 { op = 5; }
\n                  { printf("\nThe result: %f\n\n", a); a = 0; op = 0; }
[ \t]               ;  // Ignore whitespace
.                   ;  // Ignore unknown characters
%%

void digi()
{
    if (op == 0)
        a = atof(yytext);
    else {
        b = atof(yytext);
        switch (op) {
            case 1: a = a + b; break;
            case 2: a = a - b; break;
            case 3: a = a * b; break;
            case 4: a = a / b; break;
            case 5: a = pow(a, b); break;
        }
        op = 0;
    }
}

int main()
{
    printf("Enter an expression (end with ENTER):\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
