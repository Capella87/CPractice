#include <stdio.h>
#define SIZE 10

int main(void)
{
    char arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%c", &arr[i]);
        if (arr[i] >= 'A' && arr[i] <= 'Z')
            printf(" %c", arr[i]);
    }
    putchar('\n');
    return 0;
}