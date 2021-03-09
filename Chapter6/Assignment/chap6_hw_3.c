#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
            printf(" ");
        for (int k = 0; k < 2 * i + 1; k++)
            printf("*");
        putchar('\n');
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < i + 1; j++)
            printf(" ");
        for (int k = 0; k < 2 * (n - i - 1) - 1; k++) // 밑으로 내려갈 수록 *가 줄어들어야 한다; 마지막에 -1은 홀수개로 나오기 위함
            printf("*");
        putchar('\n');
    }
    
    return 0;
}