#include <stdio.h>

int main(void)
{
    int n, m;
    int gcd = 0;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= (n > m ? m : n); i++)
        if (n % i == 0 && m % i == 0)
            gcd = i;
    printf("%d\n", gcd);
    
    return 0;
}