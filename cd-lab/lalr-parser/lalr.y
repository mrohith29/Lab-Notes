%{
#include <stdio.h>
#include <stdlib.h>
%}

%union {
    double dval;
}

%token <dval> DIGIT
%type <dval> expr term factor

%%

line:
    expr '\n' {
        printf("Result: %g\n", $1);
    }
;

expr:
    expr '+' term { $$ = $1 + $3; }
  | expr '-' term { $$ = $1 - $3; }
  | term
;

term:
    term '*' factor { $$ = $1 * $3; }
  | term '/' factor {
        if ($3 == 0) {
            yyerror("Division by zero!");
            exit(1);
        }
        $$ = $1 / $3;
    }
  | factor
;

factor:
    '(' expr ')' { $$ = $2; }
  | DIGIT
;

%%

int main() {
    printf("Enter an arithmetic expression (Ctrl+D to end):\n");
    return yyparse();
}

int yyerror(char *s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
    return 0;
}
