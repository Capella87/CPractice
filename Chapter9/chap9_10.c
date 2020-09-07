#include <stdio.h>

void gcdlcm(int, int, int*, int*);

int main(void)
{
    int a, b, gcd, lcm;

    scanf("%d %d", &a, &b);
    gcdlcm(a, b, &gcd, &lcm);
    printf("%d %d\n", gcd, lcm);
    return 0;
}

void gcdlcm(int a, int b, int* gcd, int* lcm)
{
    int i;

    for (i = 1; i <= (a > b ? b : a); i++)
    {
        if (a % i == 0 && b % i == 0)
            *gcd = i;
    }
    *lcm = (a * b) / *gcd;
}