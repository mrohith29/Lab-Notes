#include<stdio.h>

void main() {
    int p[10];
    int tat[10], wt[10], i, n, pt[10], bt[10];
    float avg = 0, tot = 0;
    printf("Enter the number of processes : ");
    scanf("%d",&n);

    for(i=0; i<n; i++) {
        printf("Enter process %d number: \n", i+1);
        scanf("%d", &p[i]);
        printf("Enter process time ");
        scanf("%d", &pt[i]);
    }
    wt[0] = 0;
    for(i=1; i<n; i++) {
        wt[i] = pt[i-1] + wt[i-1];
        tot = tot + wt[i];
    }
    avg = (float)tot/n;
    for(i=0; i<n; i++) {
        tat[i] = pt[i] + wt[i];
    }
    printf("p_number\tP_time\tw_time\tturn around time\n");
    for(i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\n",p[i],pt[i],wt[i],tat[i]);
    }
    printf("total waiting time=%f\n avg waiting time=%f",tot,avg);
}

/**
 * 
 */