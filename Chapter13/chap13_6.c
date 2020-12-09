#include <stdio.h>
#include <stdlib.h>

void ABC(int (*)[20], int, int);

int main(void)
{
    int N, i, j;
    scanf("%d", &N);
    int arr[N][20];
    ABC(arr, N, N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf(" %d", *(*(arr + i) + j));
        putchar('\n');
    }

    return 0;
}

void ABC(int(*p)[20], int k1, int k2)
{
    for (int i = 0; i < k1; i++)
        for (int j = 0; j < k2; j++)
            (*(p + i))[j] = i + j;
}