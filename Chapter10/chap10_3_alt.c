#include <stdio.h>
#include <string.h>
#define MAX 100

int main(void)
{
    char str[MAX + 2];
    int i, n;
    
    scanf("%s", str);
    n = (int)strlen(str);

    for (i = 0; i < n; i++)
    {
        printf("%s\n", str + i);
        str[n + i] = str[i];
        str[n + i + 1] = '\0';
    }

    return 0;
}
