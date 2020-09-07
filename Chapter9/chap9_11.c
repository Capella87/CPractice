#include <stdio.h>
#define SIZE 6

void strcopy(char[], char[]);

int main(void)
{
    int i;
    char ch;
    char a[SIZE], b[SIZE];

    for (i = 0; i < SIZE; i++)
        *(b + i) = getchar();
    strcopy(a, b);
    for (i = 0; i < SIZE; i++)
        printf("%c", *(a + i));
    putchar('\n');

    return 0;
}

void strcopy(char destination[], char source[])
{
    int i;
    for (i = 0; i < SIZE; i++)
        *(destination + i) = *(source + i);
}
