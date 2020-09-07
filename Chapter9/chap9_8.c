#include <stdio.h>
#define MAX 50

void swap(int*, int*);

int main(void)
{
    int n;
    int arr[MAX];
    // 일단 50으로 정의하지만, VLA; Variable Length Array;가변길이배열; 를 통해 선언하거나 (C99; VS는 지원하지 않음), 동적 할당으로 n만큼만 할당 할 수 있다.
    int* pos = arr;
    int src, dest;

    scanf("%d", &n);
    for (; pos < arr + n; pos++)
        scanf("%d", pos);
    scanf("%d %d", &src, &dest);
    swap(arr + src, arr + dest);
    for (pos = arr; pos < arr + n; pos++)
        printf(" %d", *pos);
    putchar('\n');
    return 0;
}

void swap(int* from, int* to)
{
    int temp;
    temp = *from;
    *from = *to;
    *to = temp;
}