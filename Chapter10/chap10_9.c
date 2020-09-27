#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 30

int check(char*);

int main(void)
{
    char input[MAX + 1];
    char* pch;

    scanf("%30s", input);
    printf("%zd %d\n", strlen(input), check(input));
    
    return 0;
}

int check(char* src)
{
    int size = strlen(src);
    bool flag = true;
    char* pos = src, *pos2 = src + size - 1;

    for (; pos < src + size / 2; pos++, pos2--)
    {
        if (*pos != *pos2)
        {   
            flag = false;
            break;
        }
    }

    return (flag == true ? 1 : 0);
}
