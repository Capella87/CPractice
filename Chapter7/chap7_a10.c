#include <stdio.h>
#define SIZE 10

int main(void)
{
    double input[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%lf", &input[i]);
        if (input[i] > 0)
            printf(" %.1lf", input[i]);
    }
    return 0;
}