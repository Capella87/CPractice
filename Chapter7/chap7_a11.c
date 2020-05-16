#include <stdio.h>
#define SIZE 10

int main(void)
{
    double min, input[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%lf", &input[i]);
        if (i == 0)
            min = input[0];
        if (min >= input[i])
            min = input[i];
    }
    printf("%.1lf\n", min);
    return 0;
}