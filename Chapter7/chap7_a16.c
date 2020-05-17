#include <stdio.h>

int main(void)
{
    int n, i = 0;
    char x[10];
    int num[10];

    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
        scanf("%c", &x[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &num[i]);

    for (i = 0; i < n; i++)
        printf("x[%d%c%d]=x[%d]=%c\n", num[i], '%', n, num[i] % n, x[num[i] % n]);
    return 0;
}