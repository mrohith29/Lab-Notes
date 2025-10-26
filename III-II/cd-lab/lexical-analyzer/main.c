#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *s = (char *)calloc(20000, sizeof(char));
    char *t = (char *)calloc(20000, sizeof(char));

    const char *key[32] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
        "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };

    int i = 0, j, k = 0, c;
    char filename[100], ch;
    FILE *fp;

    printf("Enter a file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File cannot be opened.\n");
        free(s);
        free(t);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        s[k++] = ch;
    }
    s[k] = '\0';
    fclose(fp);

    printf("\nFile content:\n%s\n", s);
    printf("---------------------------------------\n");

    while (s[i] != '\0') {
        j = 0;
        c = 0;

        if (s[i] == '#') {
            i++;
            printf("#");
            while (s[i] != '\n' && s[i] != '\0') {
                printf("%c", s[i++]);
            }
            printf(" is a preprocessor directive\n");
        }

        else if (isalpha(s[i]) || s[i] == '_') {
            while (isalnum(s[i]) || s[i] == '_') {
                t[j++] = s[i++];
            }
            t[j] = '\0';

            for (k = 0; k < 32; k++) {
                if (strcmp(t, key[k]) == 0) {
                    c = 1;
                    break;
                }
            }

            if (c)
                printf("%s is a keyword\n", t);
            else if (s[i] == '(')
                printf("%s is a method\n", t);
            else
                printf("%s is an identifier\n", t);
        }

        else if (s[i] == '"') {
            printf("\"");
            i++;
            while (s[i] != '"' && s[i] != '\0') {
                printf("%c", s[i++]);
            }
            if (s[i] == '"') i++;
            printf("\" is an argument\n");
        }

        else if (s[i] == '/' && s[i + 1] == '/') {
            i += 2;
            printf("//");
            while (s[i] != '\n' && s[i] != '\0') {
                printf("%c", s[i++]);
            }
            printf(" is a single-line comment\n");
        }

        else if (s[i] == '/' && s[i + 1] == '*') {
            i += 2;
            printf("/*");
            while (!(s[i] == '*' && s[i + 1] == '/') && s[i] != '\0') {
                printf("%c", s[i++]);
            }
            if (s[i] == '*') {
                printf("*/");
                i += 2;
            }
            printf(" is a multi-line comment\n");
        }

        else if (s[i] == '[' || s[i] == ']' || s[i] == '(' || s[i] == ')' ||
                 s[i] == '{' || s[i] == '}') {
            printf("%c is a special symbol\n", s[i++]);
        }

        else if (isdigit(s[i])) {
            printf("%c", s[i++]);
            while (isdigit(s[i]) || s[i] == '.') {
                printf("%c", s[i++]);
            }
            printf(" is a number\n");
        }

        else if (s[i] == '=' || s[i] == '+' || s[i] == '-' || s[i] == '*' ||
                 s[i] == '/' || s[i] == '%' || s[i] == '<' || s[i] == '>' ||
                 s[i] == '&' || s[i] == '|') {
            printf("%c is an operator\n", s[i++]);
        }

        else if (s[i] == ';') {
            printf("%c is a terminator\n", s[i++]);
        }

        else {
            i++;
        }
    }

    free(s);
    free(t);
    return 0;
}
