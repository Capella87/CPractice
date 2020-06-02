#include <stdio.h>
#include <limits.h>

int add_digits(int);

int main(void)
{
    int n; // 변수 선언
    int root; // 디지털근 변수
    int min = INT_MAX, num = 0; // 가장 작은 디지털근을 저장할 변수와 그 근을 갖고 있는 수 저장할 변수 선언

    while (1)
    {
        scanf("%d", &n); // 값을 입력받는다
        if (n < 0) break; // 음수 입력한 경우 루프 종료
        root = add_digits(n); // 디지털근 변수에 함수 반환값 대입
        if (min > root) // 디지털근이 더 작은 수가 발견된 경우
        {
            min = root; // 가장 작은 디지털근 대입
            num = n;
        }
    }
    printf("%d %d\n", num, min); // 가장 작은 정수와 근 값 출력
    return 0;
}

int add_digits(int n) // 자릿수를 계산하는 함수
{
    int sum = 0; // 합을 저장할 변수
    while (1)
    {       
        sum += n % 10; // 자릿수를 더한다.
        n /= 10; // 처리한 자릿수 삭제
        if (n == 0 && sum >= 10) // 자릿수 다 처리했는데 sum이 10을 넘는 겨우
        {
            n = sum; // n에 재할당
            sum = 0; // sum 초기화
        }
        else if (n == 0 && sum < 10) break; // sum이 10 미만인 경우 루프 종료 후 반환 준비
    }
    return sum; // 자릿수 합을 반환
}