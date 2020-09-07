#include <stdio.h>
#define MAX 100

int arrsum(int*, int*);

int main(void)
{
    int n, s, e;
    int i;
    int arr[MAX];
    int* pos = arr;

    scanf("%d %d %d", &n, &s, &e);
    for (; pos < arr + n; pos++)
        scanf("%d", pos);
    printf("%d\n", arrsum(arr + s, arr + e));

    return 0;
}

int arrsum(int* start, int* end)
{
    int total = 0;
    int* where = start;

    for (; where <= end; where++)
        total += *where;
    return total;
}
