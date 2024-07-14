#include<stdio.h>
#include<string.h>

int n;

void main() {
    int b[20], i, sz[10],  b1[20], j, blocks[20][20];
    char F[20][20], S[20], ch;
    printf("\nEnter no. of Files ::");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("\nEnter file %d name ::", i+1);
        scanf("%s", &F[i]);
        printf("\nEnter file %d size(in kb)::", i+1);
        scanf("%d", &sz[i]);
        printf("\nEnter block size of file %d :: ",i+1);
        scanf("%d", &b[i]);
    }
    for(i=0; i<n; i++) {
        b1[i] = (sz[i]*1024) /b[i];
        printf("\n\nEnter blocks for file %d", i+1);
        for(j=0; j<b1[i]; j++) {
            printf("\nEnter the %d blocks :: ", j+1);
            scanf("%d", &blocks[i][j]);
        }
    }

    do {
        printf("\nEnter the filename :: ");
        scanf("%s", &S);
        for (i = 0; i < n; i++)
        {
            if(strcmp(F[i], S) == 0) {
                printf("\nFname\tFsize\tBsize\tNblocks\tBlocks\n");
                printf("\n-----------------------------------\n");
                printf("\n%s\t%d\t%d\t%d\t", F[i], sz[i], b[i], b1[i]);
                for(j=0; j<b1[i]; j++) {
                    printf("%d->",blocks[i][j]);
                }
            }
        }
        printf("\n------------------------------------\n");
        printf("\nDo you want to continue :: (Y:n)");
        scanf("%d",&ch);
    }while(ch!=0);
}