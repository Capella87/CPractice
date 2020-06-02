#include <stdio.h>
#define SIZE 10

int count(int, int);

int main(void)
{
    int n, i; // 변수 선언
    int numcount[SIZE] = { 0, }; // 숫자의 개수를 저장할 배열; 0으로 모두 초기화

    while (1)
    {
        scanf("%d", &n); // n에 값을 입력받는다.
        if (n < 0) break; // 음수인 경우 루프 종료
        for (i = 0; i < SIZE; i++) // 숫자 카운트하는 루프
            numcount[i] += count(n, i); // count함수를 호출해 반환한 값을 더해준다.
    }
    for (i = 0; i < SIZE; i++) // 출력 루프
        printf("%d ", numcount[i]); // 숫자 개수를 출력한다.
    putchar('\n');
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