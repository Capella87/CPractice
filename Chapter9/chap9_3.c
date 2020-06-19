#include <stdio.h>

int main(void)
{
    int ar[50] = {0,};
    int n, count = 0;
    int* p;

    scanf("%d", &n);
    for (p = ar; p < ar + n; p++)
    {
        scanf("%d", p);
        if (*p == 0) break;
        else count++;
    }
    printf("%d\n", count);
    return 0;
}