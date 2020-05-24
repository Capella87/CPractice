#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

// This code consumed less time than chap7_a7.c code when running the code.

int main(void)
{
    int x[SIZE], i;
    bool flag;

    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &x[i]);
    }
    for (i = 0; i < SIZE; i++)
    {
        flag = false;
        for (int j = 0; j < i; j++)
        {
            if (x[j] == x[i])
                flag = true;
        }
        if (flag == true)
            continue;
        printf(" %d", x[i]);
    }
    putchar('\n');
    return 0;
}