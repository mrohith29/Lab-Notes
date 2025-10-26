%{
#include <stdio.h>
#include <stdlib.h>
int COMMENT = 0;
int cnt = 0;
FILE *yyin;
%}

identifier [a-zA-Z_][a-zA-Z0-9_]*
keyword int|float|char|double|while|for|do|if|break|continue|void|switch|case|long|struct|const|typedef|return|else|goto

%%

"#".*                              { if (!COMMENT) printf("\n%s is a PREPROCESSOR DIRECTIVE", yytext); }

{keyword}                          { if (!COMMENT) printf("\n%s is a KEYWORD", yytext); }

"/*"                               { COMMENT = 1; }

"*/"                               { COMMENT = 0; cnt++; }

{identifier}\(                    { if (!COMMENT) printf("\n\nFUNCTION\n\t%s", yytext); }

"{"                                { if (!COMMENT) printf("\n BLOCK BEGINS"); }

"}"                                { if (!COMMENT) printf("\n BLOCK ENDS"); }

{identifier}(\[[0-9]*\])?          { if (!COMMENT) printf("\n%s is an IDENTIFIER", yytext); }

\".*\"                             { if (!COMMENT) printf("\n%s is a STRING", yytext); }

[0-9]+                             { if (!COMMENT) printf("\n%s is a NUMBER", yytext); }

"\)=" | "\);"                      { if (!COMMENT) printf("\n\t%s", yytext); }

"("                                { if (!COMMENT) printf("\n\t%s", yytext); }

"="                                { if (!COMMENT) printf("\n%s is an ASSIGNMENT OPERATOR", yytext); }

"<="|">="|"<"|">"|"=="             { if (!COMMENT) printf("\n%s is a RELATIONAL OPERATOR", yytext); }

[ \t\n]+                           { /* Ignore whitespace */ }

.                                  { /* Ignore other characters */ }

%%

int main(int argc, char **argv)
{
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            printf("Could not open %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }

    yylex();
    printf("\n\nTotal number of comments: %d\n", cnt);
    return 0;
}

int yywrap()
{
    return 1;
}
