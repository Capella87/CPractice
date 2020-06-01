#include <stdio.h>

int sum(int);

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));

    return 0;
}

int sum(int to)
{
    int total = 0;
    for (int i = 1; i <= to; i++)
        total += (i * (i + 1)) / 2;
    return total;
}