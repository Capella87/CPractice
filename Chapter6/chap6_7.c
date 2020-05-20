#include <stdio.h>

int main(void)
{
    int n, c = 1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf(" %d", c++);
            if (c % 10 == 0)
                c = 0;
        }
        printf("\n");
    }
    return 0;
}