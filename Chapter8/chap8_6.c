#include <stdio.h>

int func1(int);

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", func1(n));

    return 0;
}

int func1(int n)
{
    return 2 * n * n - 5 * n + 1;
}