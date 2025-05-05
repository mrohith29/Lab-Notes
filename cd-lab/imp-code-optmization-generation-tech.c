#include <stdio.h>
#include <conio.h>
#include <string.h>
struct regis
{
    char var;
} reg[10];
int noreg = 0;
char st[10][10];
int nost;
char *opcode[10] = {"ADD", "SUB", "MUL", "DIV"};
char oper[10] = {'+', '-', '*', '/'};
char *toopcode(char opert)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (oper[i] == opert)
        {
            return (opcode[i]);
        }
    }
}
int isinregister(char var)
{
    int i;
    for (i = 1; i <= noreg; i++)
    {
        if (var == reg[i].var)
        {
            return (i);
        }
    }
    return (0);
}
void main()
{
    int i, regno2 = 0, regno1 = 1, k, j;
    int nost1, n, flag = 0;
    // clrscr();
    printf("TO GENERATE OPTIMIZED TARGET MACHINE CODE FOR ANINTERMEDIATE CODE");
    printf("\nEnter the no. of statements:");
    scanf("%d", &nost);
    nost1 = nost;
    printf("Enter the statements:");
    for (i = 0; i < nost; i++)
    {
        scanf("%s", st[i]);
    }
    for (k = 0; k < nost - 1; k++)
    {
        for (j = 2; j < 5; j++)
        {
            if (st[k][j] != st[k + 1][j])
                flag = 1;
        }
    }
    printf("If the machine architecture is having the following format \n OPERATIONSSOURCE TARGET\n");
    printf("ADD var/reg var/reg :--> MOV b,r1 ,variable b contents are moved to register r1\n");
    printf("\n\n\tTstatements \t\t\t targetcode");
    for (i = 0; i < nost; i++)
    {
        printf("\n\t%s", st[i]);
        if ((!regno1 == isinregister(st[i][2])))
        {
            printf("\n\t\t\t\t MOV %c,r%d", st[i][2], ++noreg);
            reg[noreg].var = st[i][2];
            regno1 = noreg;
        }
        if ((!regno2 == isinregister(st[i][4])))
        {
            printf("\n\t\t\t\t %s r%d,r%d\n", toopcode(st[i][3]), regno2, regno1);
            reg[regno1].var = st[i][0];
        }
        else
        {
            printf("\n\t\t\t\t %s %c,r%d\n", toopcode(st[i][3]), st[i][4], regno1);
            reg[regno1].var = st[i][0];
        }
        // if(i==nost-1)
        {
            printf("\t\t\t\t MOV r%d,%c\n", regno1, st[i][0]);
        }
        if (flag == 0)
        {
            // printf("\t\t\t\t MOV r%d,%c\n",regno1,st[i+1][0]);
            printf("\t%s\t\t\t MOV r%d,%c\n", st[i + 1], regno1, st[i + 1][0]);
            break;
        }
    }
    printf("\n CODE GENERATION COMPLETED\n\n");
}