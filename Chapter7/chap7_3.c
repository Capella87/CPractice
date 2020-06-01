#include <stdio.h>
#include <limits.h>
#define SIZE 5

// 혼자 생각하지 못했던 문제
// 가장 큰 수와 두번째로 큰 수를 출력하는 문제

int main(void)
{
    int x[SIZE];
    int max, max2, i, pos;

    for (i = 0; i < SIZE; i++)
        scanf("%d", &x[i]);
    max = INT_MIN; //
    max2 = INT_MIN;

    for (i = 0; i < SIZE; i++)
        if (max < x[i])
        {
            max = x[i];
            pos = i;
        }
    for (i = 0; i < SIZE; i++)
    {
        if (x[i] > max2 && pos != i)
            max2 = x[i];
    }
    printf("%d\n%d\n", max, max2);
    return 0;
}