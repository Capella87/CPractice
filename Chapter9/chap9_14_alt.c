#include <stdio.h>

int add_to_k(int*, int*);

int main(void) // code with two static variables in add_to_k()
{
    int d[100];
    int n, total = 0;
    int* pos = d;

    scanf("%d", &n);
    for (; pos < d + n; pos++)
    {
        scanf("%d", pos);
        if (pos == d + n - 1)
            total = add_to_k(d, pos);
        else add_to_k(d, pos);
    }
    printf("%d\n", total);
    
    return 0;
}

int add_to_k(int* a, int* b)
{
    static int total = 0;
    static int b4 = 0;

    total += b4 + *b;
    b4 += *b;
    return total;
}
