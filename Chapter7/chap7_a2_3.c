#include <stdio.h>
#define NUMBERS 6
#define SPELLINGS 5

// 각 숫자에 해당되는 영어 단어를 출력한다.

int main(void)
{
    char x[NUMBERS][SPELLINGS] = { {'Z', 'E', 'R', 'O', '-'}, {'O', 'N', 'E', '-', '-'}, {'T', 'W', 'O', '-', '-'},
        {'T', 'H', 'R', 'E', 'E'},{'F', 'O', 'U', 'R', '-'}, {'F', 'I', 'V', 'E', '-'} };
    int input[3];
    int i, j;

    for (i = 0; i < 3; i++)
    {
        scanf("%d", &input[i]);
        for (j = 0; j < SPELLINGS; j++)
            putchar(x[input[i]][j]);
        putchar('\n');
    }
    return 0;
}