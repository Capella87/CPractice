#include <stdio.h>
#include <stdlib.h>

// 유클리드 호제법; 큰 수에서 작은 수를 뺀 것과 작은 수를 다시 대입 (재귀함수)

int gcd(int, int);

int main(void)
{
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%d\n",gcd(a, b));

    return 0;
}

int gcd(int a, int b)
{
    if (a > b)
        return gcd(b, a - b);
    else if (a == b)
        return a;
    else
        return gcd(a, b - a);
}
