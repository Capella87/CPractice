#include <stdio.h>

int main(void)
{
    int n, i = 0, x[10];

    scanf("%d", &n);
    while (n != 0)
    {
        x[i] = n % 10;
        printf(" %d", x[i++]);
        n /= 10;
    }
    putchar('\n');
    return 0;

}