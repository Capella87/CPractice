#include <stdio.h>
#include <string.h>
#define SIZE 20

int main(void)
{
    char arr[SIZE + 1];
    char* ch = arr;
    fgets(arr, SIZE + 1, stdin);
    while (*ch != '\n' && *ch != '\0')
    {
        if (*ch >= 'a' && *ch <= 'z')
            putchar(*ch);
        ch++;
    }
    putchar('\n');
    
    return 0;
}
