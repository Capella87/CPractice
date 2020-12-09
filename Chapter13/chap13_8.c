#include <stdio.h>

int add(int, int);
int sub(int, int);
int multiply(int, int);

int main(void)
{
    int (*handle[3])(int, int);
    int x, y;
    handle[0] = add;
    handle[1] = sub;
    handle[2] = multiply;

    scanf("%d %d", &x, &y);
    printf("%d %d %d\n", handle[0](x, y), handle[1](x, y), handle[2](x, y));

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}