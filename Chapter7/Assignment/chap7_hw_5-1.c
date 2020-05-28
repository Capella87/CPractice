#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int input, count = 0;
    int saved[100] = { 0, };
    bool flag;

    while (1)
    {
        flag = false;
        scanf("%d", &input);
        if (input < 0) break;

        for (int i = 0; i < count; i++)
        {
            if (saved[i] == input)
            {
                putchar('0');
                flag = false;
                break;
            }
        }

        saved[count++] = input;
        if (!flag)
            putchar('1');
    }
    putchar('\n');

    return 0;
}