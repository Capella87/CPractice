#include <stdio.h>
#include <string.h>
#define MAX 50

int main(void)
{
    char arr1[MAX + 1];
    char arr2[MAX + 1];
    char result[MAX * 2 + 2];
    int code;

    scanf("%s", arr1);
    getchar();
    scanf("%s", arr2);
    getchar();
    code = strcmp(arr1, arr2);
    if (code > 0)
    {
        strcpy(result, arr1);
        strcat(result, arr2);
    }
    else if (code <= 0)
    {
        strcpy(result, arr2);
        strcat(result, arr1);
    }
    puts(result);

    return 0;
}
