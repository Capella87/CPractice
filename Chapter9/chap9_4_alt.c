#include <stdio.h>
#define SIZE 3

int main(void)
{
    int x[SIZE];
    int *pmed = x, *a = x, *b = x + 1, *c = x + 2;
    
    scanf("%d %d %d", a, b, c);
    if (*a > *b && *a > *c)
    {
        if (*b > *c) pmed = b;
        else pmed = c;
    }
    if (*b > *a && *b > *c)
    {
        if (*a > *c) pmed = a;
        else pmed = c;
    }
    if (*c > *a && *c > *b)
    {
        if (*a > *b) pmed = a;
        else pmed = b;
    }
    printf("%d\n", *pmed);
    return 0;
}
