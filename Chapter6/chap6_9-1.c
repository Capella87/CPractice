#include <stdio.h>

int main(void)
{
    int n, threeCnt = 0;
    scanf("%d", &n);

    while (n /= 10)
        if (n % 10 == 3)
            threeCnt++;
    printf("%d\n", threeCnt);
    
    return 0;
}