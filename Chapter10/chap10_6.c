#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20

int main(void)
{
    char str1[MAX * 2 + 2];
    char str2[MAX + 1];
    int istIdx, str1cnt = 0, str2cnt = 0, i, mode;

    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%d", &istIdx);
    scanf("%d", &mode);

    while (str1[str1cnt] != '\0')
        str1cnt++;
    while (str2[str2cnt] != '\0')
        str2cnt++;
    for (i = 0; i < (str1cnt - istIdx) + 1; i++)
        *(str1 + str1cnt + str2cnt - i) = *(str1 + str1cnt - i);
    if (!mode)
    {
        for (i = 0; i < str2cnt; i++)
            *(str1 + istIdx + i) = *(str2 + i);
    }
    else if (mode == 1)
    {
        for (i = 0; i < str2cnt; i++)
            *(str1 + istIdx + i) = *(str2 + str2cnt - 1 - i);
    }
    puts(str1);

    return 0;
}