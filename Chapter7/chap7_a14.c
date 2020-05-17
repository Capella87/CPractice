#include <stdio.h>
#define SIZE 10

int main(void)
{
    char x[SIZE], y[SIZE];
    char input; int i = 0;

    while ((input = getchar()) != '\n')
        x[i++] = input;
    i = 0;
    while ((input = getchar()) != '\n')
        y[i++] = input;
    for (i = 0; i < SIZE; i++)
        printf(" %c %c", x[i], y[i]);
    putchar('\n');
    return 0;
}