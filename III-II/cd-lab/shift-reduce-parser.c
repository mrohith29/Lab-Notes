#include <stdio.h>
#include <conio.h>
#include <string.h>
int i, j, l, n, top = 0, k, p, sl;
char in[20], apro[20], pro[20][20], sta[20], stack[20];
int s[10];
void null();
void out();
void main()
{
    // clrscr();
    printf("\n\t\tEnter the total no of production:\t");
    scanf("%d", &n);
    printf("\n\tEnter the production\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", pro[i]);
        s[i] = strlen(pro[i]) - 3;
    }
    printf("\n\t\tEnter the input string end with $:\t");
    scanf("\n%s", in);
    printf("\n\t\tInput string is:%s", in);
    printf("\n\nStack\tInput\t\tAction\n");
    printf("\n\n---------------------------------------------\n");
    stack[top] = '$';
    l = 0;
    out();
    while (in[l] != '$')
        null();
    if (stack[top] == pro[0][0] && stack[top + 1] == '\0')
        printf("\t\taccept\n");
    else
        printf("error\n");
    getch();
}
void null()
{
    int p = 0, m;
    if (in[l] != '$')
        stack[++top] = in[l++];
    printf("\t\tshift:%c\n", stack[top]);
    out();
    while (1)
    {
        if (stack[top - p] == '$')
            break;
        else
        {
            for (m = top - p, k = 0; m <= top; m++, k++)
                sta[k] = stack[m];
            sta[k] = '\0';
            sl = strlen(sta);
            for (i = 0; i < n; i++)
            {
                // printf("s1=%d\t%d",sl,s[0]);
                if (sl == s[i])
                {
                    for (j = 3, k = 0; pro[i][j] != '\0'; j++)
                    {
                        apro[k] = pro[i][j];
                        k++;
                    }
                    apro[k] = '\0';
                    if ((strcmp(sta, apro)) == 0)
                    {
                        top = top - p;
                        p = 0;
                        stack[top] = pro[i][0];
                        stack[top + 1] = '\0';
                        printf("\t\t%s\n", pro[i]);
                        out();
                    }
                }
            }
        }
        p++;
    }
}
void out()
{
    int i;
    for (i = 0; i <= top; i++)
        printf("%c", stack[i]);
    printf("\t");
    for (i = l; in[i] != '\0'; i++)
        printf("%c", in[i]);
}

/*
Enter the total no of production: 3

Enter the production
E->E+E
E->E*E
E->i

Enter the input string end with $:      i+i$
*/