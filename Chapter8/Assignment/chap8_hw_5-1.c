#include <stdio.h>

int add_digits(int);

int main(void)
{
    int n; // 변수 선언

    scanf("%d", &n); // 값을 입력받는다
    printf("%d %d\n", n, add_digits(n)); // 입력받은 값과 함수를 호출하여 반환된 값을 출력한다.
    return 0;
}

int add_digits(int n) // 자릿수를 계산하는 함수
{
    int sum = 0; // 합을 저장할 변수
    while (n != 0) // n을 0이 될때까지 나누는 루프
    {
        sum += n % 10; // 나머지 == 자릿수를 더한다.
        n /= 10; // 10으로 나누어 처리한 자릿수 삭제
    }
    return sum; // 자릿수 합을 반환
}