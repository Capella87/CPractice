#include <stdio.h>
#define NUMBER 6
#define SPELLING 5

int main(void)
{
    char x[NUMBER][SPELLING] = { 'Z', 'E', 'R', 'O', '-', 'O', 'N', 'E', '-', '-', 'T', 'W', 'O', '-', '-', 'T', 'H', 'R', 'E', 'E', 'F', 'O', 'U', 'R', '-', 'F', 'I', 'V', 'E', '-' };
    int i, temp;

    for (i = 0; i < 3; i++)
    {
        scanf("%d", &temp);
        for (int j = 0; j < SPELLING; j++)
            printf("%c", x[temp][j]);
        putchar('\n');
    }
    return 0;
}