#include <stdio.h>

int add_digits(int);

int main(void)
{
    int n; // 변수 선언
    int root; // 디지털근 변수

    scanf("%d", &n); // 값을 입력받는다
    do
    {
        root = add_digits(n); // 디지털근 변수에 함수 반환값 대임
        n = root; // n에 다시 계산할 root값 대입
    } while (root >= 10); // root값이 한자릿수가 될때까지 일단 한번 해보고 반복
    printf("%d\n", root); // 값 출력
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