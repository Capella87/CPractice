#include <stdio.h>

void swap(int*, int*);

int main(void)
{
    int n, *a = NULL, *b = NULL, i, j;
    int arr[50];
    int* ptr;

    scanf("%d", &n);
    for (ptr = arr; ptr < arr + n; ptr++)
        scanf("%d", ptr);
    scanf("%d %d", &i, &j);
    a = arr + i, b = arr + j;
    swap(a, b);
    for (ptr = arr; ptr < arr + n; ptr++)
        printf(" %d", *ptr);
    putchar('\n');
    return 0;
}

void swap(int* first, int* second)
{
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}