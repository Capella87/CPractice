#include <stdio.h>

double euler(int);
unsigned long long factorial(int);

int main(void)
{
    int num;

    scanf("%d", &num);
    printf("%.6lf\n", euler(num));

    return 0;
}

double euler(int num)
{
    double result = 0.0;

    while (num >= 1)
        result += (1 / (double)factorial(num--));
    result += 1;

    return result;
}

unsigned long long factorial(int num)
{
    if (num >= 1)
        return num * factorial(num - 1);
    else
        return 1;
}