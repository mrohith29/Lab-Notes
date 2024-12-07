#include<stdio.h>
#include<string.h>

int n;
void main() {
    int b[20], i, sz[20], b1[20], j, x, blocks[20][20];
    char F[20][20], S[20], ch;
    int sb[20], eb[20];
    printf("Enter no. of files :: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("\nEnter file %d name :: ", i+1);
        scanf("%s", &F[i]);
        printf("\nEnter the file %d size(in kb):: ",i+1);
        scanf("%d", &sz[i]);
        printf("\nEnter blocksize of File %d(in bytes):: ",i+1);
        scanf("%d", &b[i]);
    }
    for(i=0; i<n; i++) {
        b1[i] = (sz[i]*1024)/b[i];
        printf("\nENter starting block of file %d :: ", i+1);
        scanf("%d", &sb[i]);
        printf("\nEnter Ending block of file %d ::", i+1);
        scanf("%d", &eb[i]);
        printf("\nEnter blocks of files %d :: \n",i+1);
        for(j=0; j<b1[i]-2;) {
            printf("\nEnter the %dblock ::",j+1);
            scanf("%d", &x);
            if(x>sb[i] && x<eb[i]) {
                blocks[i][j] = x;
                j++;
            }
            else {
                printf("\nInvalid block:: ");
            }
        }
    }
    do {
        printf("\nEnter the Filename:: ");
        scanf("%s", &S);
        for(i=0; i<n; i++) {
            if(strcmp(F[i], S) == 0) {
                printf("\nTName\tFsize\tBsize\tNblocks\tBlocks\n");
                printf("\n-----------------------------\n");
                printf("\n%s\t%d\t%d\t%d\t", F[i],sz[i],b[i], b1[i]);
                printf("%d->",sb[i]);
                for(j=0; j<b1[i]-2; j++) {
                    printf("%d->", blocks[i][j]);
                }
                printf("%d->", eb[i]);
            }
        }
        printf("\n-------------------------------\n");
        printf("\nDo you want to continue (y:n):: ");
        scanf("%d",&ch);
    }while(ch!=0);
}