#include <stdio.h>
#define SIZE 10

void ABC(int*, int);

int main(void)
{
    int arr[SIZE];
    int* pos = arr;

    for (; pos < arr + SIZE; pos++)
        scanf("%d", pos);
    pos = arr;
    for (int i = 10; i >= 2; i--)
        ABC(pos++, i);
    for (pos = arr; pos < arr + SIZE; pos++)
        printf(" %d", *pos);
    putchar('\n');
    return 0;
}

void ABC(int* start, int count)
{
    int* pos = start;
    int temp;
    int* max = start;

    for(; pos < start + count; pos++)
    {
        if (*max < *pos)
            max = pos;
    }
    temp = *start;
    *start = *max;
    *max = temp;
}
