#include <stdio.h>

int func2(int, int, int, int);

int main(void)
{
    int x, a1, a2, b1, b2, c1, c2;

    scanf("%d %d %d %d", &x, &a1, &b1, &c1);
    scanf("%d %d %d", &a2, &b2, &c2);

    printf("%d\n", func2(func2(x, a1, b1, c1), a2, b2, c2));
    return 0;
}

int func2(int x, int a, int b, int c)
{
    return a * x * x + b * x + c;
}