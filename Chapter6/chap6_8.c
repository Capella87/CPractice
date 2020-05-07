#include <stdio.h>

int main(void)
{
    int m, n, total;

    scanf("%d %d", &m, &n);

    for (int i = m; i <= n; i++)
    {
        total = 1; // 팩토리얼이 올라갈 때마다 total을 1로 초기화;
        printf("%d!=", i);
        for (int j = 1; j <= i; j++)
        {
            total *= j;
            printf("%d*", j);
        }
        printf("=%d\n", total);
    }
    return 0;
}