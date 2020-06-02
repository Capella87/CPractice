#include <stdio.h>

int count(int, int); // 카운터 함수

int main(void)
{
    int n, m; // 두 변수 선언

    scanf("%d %d", &n, &m); // 두 변수에 각각 값을 입력 받는다.
    printf("%d\n", count(n, m)); // count 함수가 반환한 값을 인쇄
    return 0;
}

int count(int n, int m)
{
    int cnt = 0; // m이 나온 횟수를 저장하는 변수
    while (n != 0) // n을 전부 나눌때까지 반복
    {
        if (n % 10 == m) cnt++; // n의 자릿수가 m과 같은 경우 count 값을 1 증가시킴
        n /= 10; // n을 10으로 나누어 처리한 자릿수 삭제
    }
    return cnt; // cnt 변수를 반환
}