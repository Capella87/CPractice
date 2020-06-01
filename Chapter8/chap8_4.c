#include <stdio.h>

void print_row1(int);
void print_row2(int);

int main(void)
{
    int n;
    
    scanf("%d", &n);
    print_row1(n);
    for (int i = 0; i < n - 2; i++)
        print_row2(n);
    print_row1(n);
    return 0;
}

void print_row1(int x)
{
    for (int i = 0; i < x; i++)
        printf("%d", x);
    putchar('\n');
}

void print_row2(int x)
{
    for (int i = 0; i < x; i++)
    {
        if (i == 0 || i == x - 1)
            printf("%d", x);
        else
            printf(" ");
    }
    putchar('\n');
}