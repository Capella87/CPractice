#include <stdio.h>

int main(void)
{
    int n, j;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
            printf(" ");
        for (; j < n + i; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}