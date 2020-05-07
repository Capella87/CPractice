#include <stdio.h>

int main(void)
{
    int n, total = 0;
    scanf("%d", &n);
    while (n != 0)
    {
        total += n;
        scanf("%d", &n);
    }
    printf("%d\n", total);
}