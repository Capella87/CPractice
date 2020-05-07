#include <stdio.h>

int main(void)
{
    int n, threeCnt = 0;
    scanf("%d", &n);

    while (n != 0)
    {
        if (n % 10 == 3)
            threeCnt++;
        n /= 10;
    }
    printf("%d\n", threeCnt);
    return 0;
}