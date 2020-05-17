#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

int main(void)
{
    int x[SIZE][2], i;

    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &x[i][0]);
        x[i][1] = false;
    }
    for (i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (j == i) continue;
            if (x[j][0] == x[i][0])
                x[j][1] = true;
        }
        if (x[i][1] == false)
            printf(" %d", x[i][0]);
    }
    putchar('\n');
    return 0;
}