#include <stdio.h>
#include <stdlib.h>
void main()
{
    int i, j, n, x, x1 = 10, x2;
    n = 10;
    i = 1;
    j = 1;
    printf("no .of frames is %d", n);
    // getch();
    while (n > 0)
    {
        printf("\n sending frames is %d", i);
        x = rand() % 10;
        if (x % 10 == 0)
        {
            for (x2 = 1; x2 < 2; x2++)
            {
                printf("\n waiting for %d seonds in \n ", x2);
                // sleep(x2);
            }
            printf("\n sending frames is %d ", i);
            x = rand() % 10;
        }
        printf("\n ack for frame is %d \n ", j);
        n = n - 1;
        i++;
        j++;
    }
    printf("\n end of stop and wait protocol \n");
    // getch();
}