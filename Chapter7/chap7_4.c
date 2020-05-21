#include <stdio.h>
#define SIZE 10

int main(void)
{
    int x[SIZE], i, one = 0, two = 0, three = 0;

    for (i = 0; i < SIZE; i++)
        scanf("%d", &x[i]);

    for (i = 0; i < SIZE; i++)
    {
        if (x[i] == 1)
            one++;
        else if (x[i] == 2)
            two++;
        else if (x[i] == 3)
            three++;
    }

    printf("1:");
    for (i = 0; i < one; i++)
        printf("*");
    printf("\n2:");
    for (i = 0; i < two; i++)
        printf("*");
    printf("\n3:");
    for (i = 0; i < three; i++)
        printf("*");
    printf("\n");

    return 0;
}