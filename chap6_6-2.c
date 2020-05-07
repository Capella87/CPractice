#include <stdio.h>

int main(void)
{
    int n; int k = 1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d", k);
            if (k == 9)
                k = 0;
            else
                k++;
        }
        printf("\n");
    }
    return 0;
}