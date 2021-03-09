#include <stdio.h>

int main(void)
{
    int n;
    
    scanf("%d", &n);
    while (n > 1 && n % 3 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
                printf(" ");
            for (int k = 0; k < 2 * i + 1; k++)
            {
                if (k == 0 || k == 2 * i || i == n - 1)
                    printf("X");
                else
                    printf("O");
            }
            printf("\n");
        }
        scanf("%d", &n);
    }

    return 0;
}