#include <stdio.h>
#define SIZE 5

int main(void)
{
    int x[SIZE], i;
    double mean = 0.0;

    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &x[i]);
        mean += (double)x[i];
    }
    mean /= SIZE;
    for (i = 0; i < SIZE; i++)
        if((double)x[i] > mean)
            printf("%d\n", x[i]);

    return 0;
}