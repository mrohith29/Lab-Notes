#include<stdio.h>
#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, highest = 0;
    static int bf[max], ff[max];
    printf("\nMemory management scheme-first fit");
    printf("\nEnter number of blocks: ");
    scanf("%d", &nb);
    printf("\nEnter the number of files: ");
    scanf("%d", &nf);
    printf("Enter the size of blocks: ");
    for(i=1; i<=nb; i++) {
        printf("\nBlock %d: ",i);
        scanf("%d", &b[i]);
    }
    printf("\nEnter size of files: ");
    for(i=1; i<= nf; i++) {
        printf("\nFile %d: ",i);
        scanf("%d", &f[i]);
    }

    for(i=1; i<=nf;i++) {
        for(j=1; j<=nb; j++) {
            if(bf[j] != 1) {
                temp = b[j] - f[i];
                if(temp >= 0) {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }
    printf("\nFile no\tfile size\tblock no\tblock size\tfragment");
    for(i=1; i<=nf; i++) {
        printf("\n%d\t%d\t%d\t%d\t%d",i,f[i],ff[i],b[ff[i]], frag[i]);
    }
}