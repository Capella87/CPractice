#include <stdio.h>

int main(void)
{
    int n, j = 0, input, count = 0, i = 0, k;
    int score[100], further[100];

    scanf("%d", &n);
    if (n < 0 || n > 100)
    {
        printf("ERROR\n");
        return -1;
    }
    while (i < n)
    {
        scanf("%d", &input);
        if (input < 0 || input > 100)
        {
            printf("ERROR\n");
            return -1;
        }
        score[i++] = input;
    }
    while (n > 1)
    {
        count = 0;
        for (j = 0; j < n; j += 2)
        {
            if (n - j == 1)
            {
                further[count++] = score[j];
                break;
            }
            further[count++] = score[j] >= score[j + 1] ? score[j] : score[j + 1];
        }
        for (k = 0; k < count; k++)
            printf("%d ", further[k]);
            putchar('\n');
        n = count;
        for (k = 0; k < n; k++)
            score[k] = further[k];
    }
    return 0;
}