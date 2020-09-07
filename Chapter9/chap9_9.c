#include <stdio.h>
#define SIZE 3

int* mid(int[]);

int main(void)
{
    int arr[SIZE];
    int i;

    for (i = 0; i < SIZE; i++)
        scanf("%d", arr + i);
    printf("%d\n", *mid(arr));
    return 0;
}

int* mid(int input[])
{
    int* md = input;

    if (*md < *(input + 1) && *md < *(input + 2))
    {
        if (*(input + 1) <= *(input + 2))
            md = input + 1;
        else
            md = input + 2;
    }
    else if (*md >= *(input + 1) && *md > *(input + 2))
    {
        if (*(input + 1) <= *(input + 2))
            md = input + 2;
        else
            md = input + 1;
    }
    return md;
}
