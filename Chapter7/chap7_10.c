#include <stdio.h>
#define SIZE 3

int main(void)
{
    int x[SIZE][SIZE];
    int sum = 0;

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            scanf("%d", &x[i][j]);
            if (i == j) sum += x[i][j];
        }
    printf("%d\n", sum);
    return 0;
}