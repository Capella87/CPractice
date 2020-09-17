#include <stdio.h>
#define SIZE 5

int main(void)
{
    int arr[SIZE];
    int rank[5] = { 0, };
    int *p, *q, *r;

    for (p = arr; p < arr + SIZE; p++)
        scanf("%d", p);
    for (p = arr, r = rank; p < arr + 5; p++, r++)
        for (q = arr; q < arr + SIZE; q++)
            if (*p < *q)
                (*r)++;
    for (p = arr, r = rank; p < arr + 5; p++, r++)
        printf("%d = r%d ", *p, *r + 1);
    return 0;
}
