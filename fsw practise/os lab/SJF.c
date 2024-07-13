#include <stdio.h>
struct sa
{
    char pro[10];
    int bt, wt, tat;
}
p[10], temp[10];
void main()
{
    int i, j, n, temp1 = 0;
    float awt = 0, atat = 0;
    printf("\n enter number of processes");
    scanf("%d", &n);
    printf("\n enter the name of process and burst time:");
    for (i = 0; i < n; i++)
    {
        scanf("%s %d", p[i].pro, &p[i].bt);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].bt > p[j].bt)
            {
                temp[i] = p[i];
                p[i] = p[j];
                p[j] = temp[i];
            }
        }
    }
    printf("\nProcess\t\tbt\t\twt\t\ttat");
    for (i = 0; i < n; i++)
    {
        p[i].wt = temp1;
        p[i].tat = p[i].bt + p[i].wt;
        awt += p[i].wt;
        atat += p[i].tat;
        temp1 = p[i].bt + temp1;
        printf("\n%s\t\t%d\t\t%d\t\t%d", p[i].pro, p[i].bt, p[i].wt, p[i].tat);
    }
    printf("\nAverage Waiting time is %f\nAverage Turn Around Time is %f", awt/n, atat/n);
}