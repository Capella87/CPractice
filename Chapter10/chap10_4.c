#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

int getLength(const char*);
int compareStr(const char*, const char*);

int main(void)
{
    char arr[MAX + 1];
    char second[MAX + 1];

    fgets(arr, MAX + 1, stdin);
    fgets(second, MAX + 1, stdin);
    printf("%d ", getLength(arr));
    printf("%d\n", compareStr(arr, second));

    return 0;
}

int getLength(const char* input) // When using pointer without modify its pointed variable's value, Utilize 'const' to prevent mutilation.
{
    int count = 0;
    while (*input != '\0' && *input != '\n')
    {
        count++;
        input++;
    }
    return count;
}

int compareStr(const char* destination, const char* src)
{
    bool flag = true;

    if (getLength(src) != getLength(destination))
        return 0;
    while (*destination != '\n' && *destination != '\0')
    {
        if (*destination != *src)
        {
            flag = false;
            break;
        }
        destination++;
        src++;
    }
    if (flag)
        return 1;
    else
        return 0;
}
