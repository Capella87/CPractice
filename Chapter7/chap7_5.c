#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

int main(void)
{
    char x[SIZE];
    int i, k = 0;
    bool flag = false;

    for (i = 0; i < SIZE; i++)
        scanf("%c", &x[i]);
    for (i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c", x[k]);
            if (k == 4)
                flag = true;
            else if (k == 0)
                flag = false;
            if (flag && j != SIZE - 1)
                k--;
            else if (!flag && j != SIZE - 1)
                k++;
        }
        printf("\n");
    }
    return 0;
}