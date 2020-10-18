#include <stdio.h>
#include <string.h>

struct _complex
{
    double real;
    double imagine;
};

struct _complex add(struct _complex, struct _complex);

int main(void)
{
    struct _complex num1, num2, total;

    scanf("%lf %lf", &num1.real, &num1.imagine);
    getchar();
    scanf("%lf %lf", &num2.real, &num2.imagine);
    total = add(num1, num2);
    printf("%.1lf + %.1lfi\n", total.real, total.imagine);

    return 0;
}

struct _complex add(struct _complex a, struct _complex b)
{
    a.real += b.real;
    a.imagine += b.imagine;
    
    return a;
}
