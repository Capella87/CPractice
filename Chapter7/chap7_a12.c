#include <stdio.h>
#define SIZE 10

int main(void)
{
    double input[SIZE];
    int count, i;

    for (i = 0; i < SIZE; i++)
        scanf("%lf", &input[i]);
    for (i = 0; i < SIZE; i++)
    {
        count = 0;
        for (int j = 0; j < SIZE; j++)
            if (input[j] < input[i])
                count++;
        printf(" %d", count);
    }
    putchar('\n');
    return 0;
}