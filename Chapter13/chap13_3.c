#include <stdio.h>

unsigned long long fibonacci(int);

int main(void)
{
    int num;

    scanf("%d", &num);
    printf("%llu\n", fibonacci(num));

    return 0;
}

unsigned long long fibonacci(int num)
{
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return fibonacci(num - 1) + fibonacci(num - 2);
}
