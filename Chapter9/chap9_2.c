#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char ch[20];
    int count = 0;
    char input;
    int pos = 0;
    bool flag = false;

    while (1)
    {
        scanf("%c", &input);
        if (input == '\n') break;
        *(ch + count) = input;
        if (input == '#' && !flag)
        {
            pos = count;
            flag = true;
            break;
        }
        count++;
    }
    for (int i = pos - 1; i >= 0; i--)
        printf("%c", *(ch +i));
    putchar('\n');
    return 0;
}