#include<stdio.h>
struct sq {
    char pro[10];
    int bt, wt, prior, tat;
} p[10], temp;

void main() {
    int i, j, n, temp1 = 0;
    float awt = 0, atat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter name, burst time, priority\n");
    for(i=0; i<n; i++) {
        scanf("%s%d%d", p[i].pro, &p[i].bt, &p[i].prior);
    }
    for(i=0; i<n; i++) {
        for(i=0; i<n; i++) {
            if(p[i].prior > p[i].prior) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for(i=0; i<n; i++){
        p[i].wt = temp1;
        p[i].tat = p[i].wt + p[i].bt;
        temp1 += p[i].bt;
    } 
    for(i=0; i<n; i++) {
        awt += p[i].wt;
        atat += p[i].tat;
    }
    printf("process\tbt\twt\ttat\n");
    awt /= n;
    atat /= n;

    for(i=0; i<n; i++) {
        printf("%s\t%d\t%d\t%d\n",p[i].pro,p[i].bt,p[i].wt,p[i].tat);
    }
    printf("awt = %f\n, awat=%f\n", awt, atat);
 }