#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

int main(void)
{
    char arr[MAX * 2];
    char ch;
    char* pos = arr;
    int cnt = 0, i, j;

    while ((ch = getchar()) != '\n')
    {
        *(pos++) = ch;
        *pos = '\0';
        cnt++;
        if (pos - arr == MAX * 2 - 1)
            break;
        else
            pos++;
    }
    for(i = 0; i < cnt; i++)
    {
        pos = arr + 2 * i;
        for (j = 0; j < cnt; j++)
        {
            printf("%s", pos);
            if (pos - arr == (cnt - 1) * 2)
                pos = arr;
            else
                pos += 2;
        }
        putchar('\n');
    }

    return 0;
}
