#include <stdio.h>

int main(void)
{
    int n, total = 0;

    scanf("%d", &n);

    while (n != 0)
    {
        total += n % 10;
        n /= 10;
    }
    printf("%d\n", total);
    return 0;
}