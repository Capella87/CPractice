#include <stdio.h>

void print_triangle(int);

int main(void)
{
    int input;

    while (1)
    {
        scanf("%d", &input);
        if (input <= 0) break;
        print_triangle(input);
    }
    return 0;
}

void print_triangle(int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j <= i; j++)
            putchar('*');
        putchar('\n');
    }
}