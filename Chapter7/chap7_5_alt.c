#include <stdio.h>
#define SIZE 5

int main(void)
{
    char input[SIZE];
    int i, j;

    for (i = 0; i < SIZE; i++)
        scanf("%c", &input[i]);

    for (i = SIZE; i > 0; i--) // 거꾸로 뒤집었다.
        for (j = 0; j < SIZE; j++)
            printf("%c", input[(i + j) % 5]);
    return 0;
}