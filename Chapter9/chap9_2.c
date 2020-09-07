#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[20];
    int count = 0;
    char ch;
    while (count < 20)
    {
        ch = getchar();
        if (ch == '#')
            break;
        *(input + count) = ch;
        count++;
    }
    for (int i = count - 1; i >= 0; i--)
        putchar(*(input + i));
    putchar('\n');
    
    return 0;
}