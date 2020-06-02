#include <stdio.h>

int count(int, int);

int main(void)
{
    int n, m, total = 0; // total 변수는 m이 나온 총 갯수를 저장하기 위함

    scanf("%d", &m); // m에 값을 입력 받는다
    while (1)
    {
        scanf("%d", &n); // n에 값을 입력받는다
        if (n < 0) break; // 음수가 나온 경우 입력 중단
        total += count(n, m); // count를 호출하여 반환된 값을 total 변수에 더함
    }
    printf("%d\n", total); // total 변수 출력
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