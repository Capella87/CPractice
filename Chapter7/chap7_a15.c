#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

int main(void)
{
    char input[SIZE];
    int i;
    bool flag = false;

    for (i = 0; i < SIZE; i++)
        scanf("%c", &input[i]);
    for (i = 0; i < SIZE; i++)
    {
        flag = false;
        for (int j = 0; j < SIZE; j++)
        {
            if (j == i)
                continue;
            if (input[j] == input[i])
                flag = true;
        }
        if (flag == false)
            printf(" %c", input[i]);
    }
    putchar('\n');
    return 0;
}