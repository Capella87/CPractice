#include <stdio.h>

int add_to_k(int*, int*);

int main(void) // code without static variable in add_to_k().
{
    int d[100];
    int n, total = 0;
    int* pos = d;

    scanf("%d", &n);
    for (; pos < d + n; pos++)
    {
        scanf("%d", pos);
        total += add_to_k(d, pos);
    }
    printf("%d\n", total);
    
    return 0;
}

int add_to_k(int* a, int* b)
{
    int total = 0;
    int* where = a;

    for (; where <= b; where++)
        total += *where;

    return total;
}
