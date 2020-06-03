#include <stdio.h>
#define SIZE 3

int main(void)
{
    char answer[SIZE];
    char status[SIZE] = { '_', '_', '_' };
    int i, count = 1;
    char ch;

    for (i = 0; i < SIZE; i++)
        scanf("%c", &answer[i]);
    getchar();

    while (count <= 5)
    {
        scanf("%c", &ch);
        getchar();
        for (i = 0; i < SIZE; i++)
        {
            if (ch == answer[i])
                status[i] = ch;
            else
                continue;
        }
        for (i = 0; i < SIZE; i++)
            printf(" %c", status[i]);
        putchar('\n');
        count++;
        if (status[0] != '_' && status[1] != '_' && status[2] != '_')
            break;
    }
    return 0;
}