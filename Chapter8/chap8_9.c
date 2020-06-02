#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int max1 = INT_MIN, max2 = INT_MIN; // 또는 전역변수로 부울형 flag2를 새로 선언하여, !flag2일때 max1과 max2에 값을 삽입해 시작할 수 있을 것이다.

void update_max(int);

int main(void)
{
    int n;

    while (1)
    {
        scanf("%d", &n);
        if (n == 0) break;
        update_max(n);
    }
    printf("%d %d\n", max1, max2);
    return 0;
}

void update_max(int n)
{
    bool flag = false;
    if (max1 < n) // max1보다 더 큰 수가 발견된 경우
    {
        max2 = max1; // 기존 max1값을 max2으로 보낸다
        max1 = n;
        flag = true; // 플래그 값을 1로 바꾼다.
    }
    if (max2 < n && n < max1) // max1보다는 작은데 max2보다는 큰 수가 나온 경우
        max2 = n;
    else if (n == max1 && !flag) // max1과 같은 수가 나온 경우; 플래그는 여기에서 max1 변수가 바뀐 상태에서 max2까지 변경하려는 것을 막는다.
        max2 = n;
}