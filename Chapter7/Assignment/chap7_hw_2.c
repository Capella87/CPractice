#include <stdio.h>
#define SIZE 10

int main(void)
{
    int x[SIZE], i, temp, oddcount = 0, evencount = 0;
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &temp);
        if (temp % 2 == 0)
            x[SIZE - 1 - evencount++] = temp;
        else
            x[oddcount++] = temp;
    }
    for (i = 0; i < SIZE; i++)
        printf("%d ", x[i]);
    putchar('\n');
    return 0;
    
}