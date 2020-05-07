#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            for (int k = 1; k <= 6; k++)
            {
                if ( i + j + k == n)
                    printf("%d %d %d\n", i, j, k);
            }
    return 0;
}