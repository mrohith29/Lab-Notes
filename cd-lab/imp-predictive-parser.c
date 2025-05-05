#include <stdio.h>
#include <string.h>
int n, z = 0, m = 0, p, i = 0, j = 0;
char a[3][10], f[10];
void follow(char c);
void first(char c);
int main()
{
    int i, j, z, n1;
    char t[10];
    int x;
    char c;
    printf("enter no of terminals");
    scanf("%d", &n1);
    scanf("%s", t);
    printf("\n enter the no. of productions");
    scanf("%d", &n);
    printf("\n enter the productions (epsilon=e) enter X and Y as alternates for E' and T'");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);
    for (i = 0; i < n; i++)
        printf("%s\n", a[i]);
    for (i = 0; i < n1; i++)
        printf("\t%c", t[i]);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        if ((islower(a[i][2])) && (a[i][2] != 'e'))
        {
            x = 0;
            printf("%c\t", a[i][0]);
            while (a[i][2] != t[x])
            {
                printf("\t");
                x++;
            }
            printf("%c->%s\n", a[i][0], a[i] + 2);
        }
        if (isupper(a[i][2]))

        {
            m = 0;
            first(a[i][2]);
            for (z = 0; z < m; z++)

            {
                if (f[z] == 'e')

                {
                    for (x = 0; x < m; x++)
                        f[m] = '\0';
                    m = 0;
                    follow(a[i][0]);
                }
            }
            printf("%c\t", a[i][0]);
            for (z = 0; z < m; z++)

            {
                x = 0;
                while (f[z] != t[x])

                {
                    printf("\t");
                    x++;
                }
                printf("%c->%s\t", a[i][0], a[i] + 2);
            }
            printf("\n");
            continue;
        }
        if (a[i][2] == 'e')

        {
            m = 0;
            follow(a[i][0]);
            printf("%c\t", a[i][0]);
            for (z = 0; z < m; z++)

            {
                x = 0;
                while (f[z] != t[x])

                {
                    printf("\t");
                    x++;
                }
                printf("%c->e", a[i][0]);
            }
            printf("\n");
            continue;
        }
    }
    return 0;
}
void follow(char c)
{
    int k, l;
    if (a[0][0] == c)
        f[m++] = '$';
    for (k = 0; k < n; k++)
    {
        for (l = 2; l < strlen(a[k]); l++)

        {
            if (a[k][l] == c)

            {
                if (a[k][l + 1] != '\0')
                    first(a[k][l + 1]);
                if ((a[k][l + 1] == '\0') && (c != a[k][0]))
                    follow(a[k][0]);
            }
        }
    }
}
void first(char c)
{
    int k;
    if (!isupper(c))
        f[m++] = c;
    for (k = 0; k < n; k++)
    {
        if (a[k][0] == c)
        {
            if (a[k][2] == 'e')
                follow(a[i][0]);
            else if (islower(a[k][2]))
                f[m++] = a[k][2];
            else
                first(a[k][2]);
        }
    }
}