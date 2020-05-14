#include <stdio.h>

int main(void)
{
    int n, r, sum;

    scanf("%d", &n);
    while (n >= 10) // 중요점; 10이 넘는 경우 루프 돌림
    {
        sum = 0;
        while (n != 0)
        {
            r = n % 10; // 자릿수 저장
            sum += r; // 자릿수 더하기
            n /= 10; // 필요 없어진 자릿수 제거
        }
        n = sum; // 자릿수 더한 후 n에 sum 대입 --> 자릿수 합이 10을 넘는 경우 재검증
    }
    printf("%d\n", sum);
    return 0;
}