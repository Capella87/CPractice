#include <stdio.h>
#define SIZE 10

int main(void)
{
    int x[SIZE], count = 0, i;

    for (i = 0; i < SIZE; i++)
        scanf("%d", &x[i]);
    for (i = 0; i < SIZE; i++)
    {
        count = 0;
        for (int j = 0; j < SIZE; j++)
            if (x[j] > x[i])
                count++;
        printf(" %d", count);
    }
    putchar('\n');
    return 0;
}