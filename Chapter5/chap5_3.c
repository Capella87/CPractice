#include <stdio.h>

int main(void)
{
    long long a, b, c, d, e, sum = 0;

    scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &e);

    if (a > 0) sum += a;
    if (b > 0) sum += b;
    if (c > 0) sum += c;
    if (d > 0) sum += d;
    if (e > 0) sum += e;
    printf("%ld\n", sum);
    return 0;
}