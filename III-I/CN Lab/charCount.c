#include<stdio.h>
#include<string.h>

int main() {
    int n;
    printf("Enter no of frames: ");
    scanf("%d", &n);
    int frames[n];
    for(int i=0; i<n; i++) {
        printf("\nEnter frame %d max_size: ", i+1);
        scanf("%d", &frames[i]);
    }
    char string[n][50];
    printf("Enter the content for each frame: \n");
    for(int i=0; i<n; i++) {
        printf("\nEnter the content for each frame: %d", i+1);
        scanf("%s", &string[i]);
        while (strlen(string[i])>frames[i]) {
            printf("Enter string exceeding the maxsize!!\nEnter again: ");
            scanf("%s", &string[i]);
        }
    }
    for(int i=0; i<n; i++) {
        int cnt = 0;
        for(int j=0; j< strlen(string[i]); j++) {
            if(string[i][j] !='\0')
            cnt++;
        }
        printf("\ncharacter count in frame %d is: %d", i+1, cnt);
    }
}