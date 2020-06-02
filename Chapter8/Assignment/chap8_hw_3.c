#include <stdio.h>

int multiple(int, int);
int maximum(int, int);
int digit_maximum(int);

int main(void)
{
    int N, M, K, max1 = 0, max2 = 0, result = 0; // 변수 선언
    scanf("%d %d %d", &N, &M, &K); // N, M, K를 입력받는다.

    for (int i = N; i <= M; i++) // N부터 M까지 더해가면서 처리한다.
    {
        switch (multiple(i, K)) // i가 K의 배수인지 아닌지에 따라 갈린다.
        {
        case 1: // 배수인 경우
            max1 = maximum(max1, digit_maximum(i)); // max1 변수는 배수인 경우 처리한 수 중 가장 큰수를 저장한다. 기존 값과 비교한다.
            break;
        case 0:
            max2 = maximum(max2, i % K); // max2 변수는 배수가 아닌 경우 처리한 수 중 가장 큰 수를 저장한다. 기존에 들어있던 값과 비교한다.
            break;
        }
        result = maximum(max1, max2); // max1과 max2중 큰 수를 result 변수에 저장한다.
    }
    printf("%d\n", result); // 결과값 출력
    return 0;
}

int multiple(int x, int y) // 배수 여부를 가리는 함수
{
    if (x % y == 0) return 1; // 배수인 경우 1을 반환한다.
    else return 0; // 그렇지 않은 경우 0을 반환한다.
}

int maximum(int x, int y) // 최댓값을 반환하는 함수
{
    return x >= y ? x : y; // x >= y가 참이면 x를 반환하고 아니면 y를 반환한다.
}

int digit_maximum(int x) // 자릿수 중 최댓값을 구해 반환하는 함수
{
    int digit, max = 0; // 각각 자릿수를 저장하는 변수와 최댓값을 저장하는 변수이다.

    while (x != 0) // 자릿수 처리 끝나기 전까지
    {
        digit = x % 10; // 자릿수 처리
        max = maximum(max, digit); // 기존에 처리해 저장했던 max값과 비교하여 최댓값을 저장한다.
        x /= 10; // 처리가 끝난 자릿수 삭제
    }
    return max; // 처리한 자릿수 중 최댓값으로 나온 것을 반환
}