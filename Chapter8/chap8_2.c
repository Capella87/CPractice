#include <stdio.h>

int sum(int, int);

int main(void)
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    printf("%d\n", sum(a, b));
    return 0;
}

int sum(int from, int to)
{
    return (to * (to + 1)) / 2 - ((from - 1) * from) / 2;
}