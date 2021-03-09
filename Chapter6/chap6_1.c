#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        if (n % i == 0)
            printf("%d ", i);
    putchar('\n');
    
    return 0;
}