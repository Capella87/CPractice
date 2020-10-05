#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    char str1[81];
    char str2[11];
    char* pos = str1, * pos2 = str2;
    char* pos3 = str1;
    size_t str2len;
    bool flag, inc = false;

    scanf("%[^\n]", str1);
    getchar();
    scanf("%[^\n]", str2);
    str2len = strlen(str2);

    printf("%zd ", strlen(str1));
    while (pos - str1 <= (int)(strlen(str1) - str2len))
    {
        flag = true;
        for (pos3 = pos, pos2 = str2; pos2 < str2 + str2len; pos2++, pos3++)
        {
            if (*pos3 != *pos2)
            {
                flag = false;
                break;
            }
        }
        if (flag && !inc)
        {
            inc = true;
            pos += str2len;
        }
        else if (flag)
            pos += str2len;
        else
            pos++;
    }
    printf("%d\n", (int)inc);
    return 0;
}