#include <stdio.h>

int main(void)
{
    int input[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &input[i]);
        if (input[i] % 2 == 0)
            printf(" %d", input[i]);
    }
    putchar('\n');
    return 0;
}