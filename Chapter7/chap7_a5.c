#include <stdio.h>
#define SIZE 10

int main(void)
{
    int x[10], max, i;

    for (i = 0; i < SIZE; i++)
        scanf("%d", &x[i]);
    max = x[0];
    for (i = 0; i < SIZE; i++)
        if (max <= x[i])
            max = x[i];
    printf("%d\n", max);
    return 0;
}