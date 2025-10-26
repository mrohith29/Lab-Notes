%{
#include <stdio.h>

int lines = 0, words = 0, s_letters = 0, c_letters = 0, num = 0, spl_char = 0, total = 0;
%}

%%
\n              { lines++; words++; }
[ \t]+          { /* ignore whitespace */ }
[A-Z]           { c_letters++; total++; }
[a-z]           { s_letters++; total++; }
[0-9]           { num++; total++; }
[^a-zA-Z0-9 \t\n] { spl_char++; total++; }
.               { total++; }  // for counting other characters
%%

int main(void)
{
    FILE *fp = fopen("hi.txt", "r");
    if (!fp) {
        perror("Cannot open file");
        return 1;
    }

    yyin = fp;
    yylex();

    printf("This File contains ...\n");
    printf("\t%d lines\n", lines);
    printf("\t%d words\n", words);
    printf("\t%d capital letters\n", c_letters);
    printf("\t%d small letters\n", s_letters);
    printf("\t%d digits\n", num);
    printf("\t%d special characters\n", spl_char);
    printf("\tIn total %d characters.\n", total);

    fclose(fp);
    return 0;
}

int yywrap()
{
    return 1;
}
x`x