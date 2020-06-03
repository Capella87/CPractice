#include <stdio.h>
#define SIZE 5

int main(void)
{
    int x[SIZE];
    int i, j, temp;

    for (i = 0; i < SIZE; i++)
        scanf("%d", &x[i]);
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - 1; j++)
        {
            if (x[j] > x[j + 1])
            {
                temp = x[j + 1];
                x[j + 1] = x[j];
                x[j] = temp;
            }
        }
    }
    for (i = 0; i < SIZE; i++)
        printf("%d\n", x[i]);
    return 0;
}