#include <stdio.h>
#define SIZE 7

int main(void)
{
    char x[SIZE];
    int i, count = 0;

    for (i = 0; i < SIZE; i++)
        scanf("%c", &x[i]);
    for (i = 0; i < SIZE; i++)
        if (x[i] == 'c' && x[i + 1] == 'a' && x[i + 2] == 't')
            count++;
    printf("%d\n", count);
    return 0;
}