#include <stdio.h>

int main(void)
{
    int n, result = 0;

    scanf("%d", &n);
    int x[n]; // VLA; Not supported on MSVC

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
        result = result * 10 + x[i];
    }
    printf("%d\n", result);
    return 0;
}