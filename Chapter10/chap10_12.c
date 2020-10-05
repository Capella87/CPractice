#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

int main(void)
{
    char str1[MAX + 1];
    char str2[MAX + 1];
    char* pos = str1, * pos2 = str2;
    char* pos3 = str1;
    size_t str2len;
    bool flag;
    int count = 0;

    scanf("%[^\n]", str1);
    getchar();
    scanf("%[^\n]", str2);
    str2len = strlen(str2);

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
        if (flag)
        {
            count++;
            pos += str2len;
        }
        else
            pos++;
    }
    printf("%d\n", count);
    return 0;
}