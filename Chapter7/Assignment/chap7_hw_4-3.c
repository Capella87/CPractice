#include <stdio.h>

int main(void)
{
    int n, i, max, min, cnt = 0;
    int input[20], input2[20];
    int critical[7][2];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
        input2[i] = input[i];
    }

    for (i = n - 1; i >= 0; i--)
        printf("%d ", input[i]);
    putchar('\n');
    
    while (1)
    {
        cnt = 0;
        
        for (i = 0; i < n; i += 3)
        {
            max = input[i];
            min = input2[i];
            for (int j = 0; j < 3; j++)
            {
                if (i + j >= n)
                    break;
                if (input[i + j] >= max)
                    max = input[i + j];
                if (input2[i + j] <= min)
                    min = input2[i + j];
            }
            critical[cnt][0] = max;
            critical[cnt++][1] = min;
        }

        for (i = 0; i < cnt; i++)
            printf("%d ", critical[i][0]);
        putchar('\n');
        
        for (i = 0; i < cnt; i++)
            printf("%d ", critical[i][1]);
        
        if (cnt == 1) break;
        n = cnt;

        for (i = 0; i < cnt; i++)
        {
            input[i] = critical[i][0];
            input2[i] = critical[i][1];
        }
        
        return 0;
    }

    return 0;
}