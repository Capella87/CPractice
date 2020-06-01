#include <stdio.h>

int add(int, int);

int main(void)
{
    int n, i = 1, result = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        result = add(result, i);
    printf("%d", result);
    return 0;
}

int add(int a, int b)
{
    return a + b;
}