#include <stdio.h>

int main(void)
{
    int n, x[20], i;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &x[i]);
    for (i = n - 1; i >= 0; i--)
        printf("%d ", x[i]);
    putchar('\n');
    return 0;
}