#include <stdio.h>
#define SIZE 10

int main(void)
{
    int x[SIZE], y[SIZE], z[SIZE], i;

    for (i = 0; i < SIZE; i++)
        scanf("%d", &x[i]);
    for (i = 0; i < SIZE; i++)
        scanf("%d", &y[i]);
    for (i = 0; i < SIZE; i++)
    {
        z[i] = x[i] + y[9 - i];
        printf(" %d", z[i]);
    }
    printf("\n");
    return 0;
}