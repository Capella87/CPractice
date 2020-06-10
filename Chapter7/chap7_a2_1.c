#include <stdio.h>
#define SIZE 3

// 대각선 원소들의 합을 출력한다.

int main(void)
{
    int darwin[SIZE][SIZE];
    int i, j;
    int total = 0;

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            scanf("%d", &darwin[i][j]);
    for (i = 0; i < SIZE; i++)
        total += darwin[i][i];

    printf("%d\n", total);
    return 0;
}