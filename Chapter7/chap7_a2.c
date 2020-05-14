#include <stdio.h>

int main(void)
{
    int input[10];
    int sum = 0;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &input[i]);
        sum += input[i];
    }
    printf("%d\n", sum);
    return 0;
}