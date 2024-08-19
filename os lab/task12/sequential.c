#include<stdio.h>
#include<string.h>

void main() {
    int st[20], i, n, sz[20], b[20], b1[20], blocks[20][20], j, ch;
    char F[20][20], S[20];
    printf("\nEnter no. of files :: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("\nEnter file %d name :: ", i+1);
        scanf("%s",&F[i]);
        printf("Enter file %d size(in kb)::", i+1);
        scanf("%d",&sz[i]);
        printf("Enter starting blocks of %d:: ",i+1);
        scanf("%d", &st[i]);
        printf("\nEnter blocksize of File %d(in bytes)", i+1);
        scanf("%d", &b[i]);
    }

    for(i=0; i<n; i++) {
        b1[i] = (sz[i]*1024)/b[i];
    }

    for(i=0; i<n; i++) {
        for(j=0; j<b1[i]; j++) {
            blocks[i][j] = st[i]+j;
        }
    }
    do {
        printf("\nEnter the filename :: ");
        scanf("%s", S);
        for(i=0; i<n; i++) {
            if(strcmp(S,F[i])==0) {
                printf("\nFname\tStart\tNblocks\tBlocks\n");
                printf("\n------------------------\n");
                printf("\n%s\t%d\t%d\t", F[i], st[i], b1[i]);
                for(j=0; j<b1[i]; j++) {
                    printf("%d->", blocks[i][j]);
                }
            }
        }
        printf("\n--------------------\n");
        printf("\nDo you want to continue :: (Y:n) ");
        scanf("%d", &ch);
        if(ch!=1){
            break;
        }
    }while(1);
}