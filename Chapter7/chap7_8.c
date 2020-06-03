#include <stdio.h>
#define SIZE 5

int main(void)
{
    int arr[SIZE];
    int i = 0, temp;

    for (i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < SIZE - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
        }
    }
    for (i = 0; i < SIZE; i++)
        printf("%d\n", arr[i]);
    return 0;
}