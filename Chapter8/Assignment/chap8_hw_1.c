#include <stdio.h>

// 아랫부분은 전부 함수 선언이다.
int num_digit(int);
int convert_top(int, int);
int convert_bottom(int, int);

// 메인 함수
int main(void)
{
    int n; // 입력받은 수를 저장할 변수
    int leftover, i, len = 0; // 이 변수들은 계산과정에서 사용된다. 

    scanf("%d", &n); // 값을 입력 받는다
    len = num_digit(n); // len에 자릿수를 저장한다.
    
    if (len % 2 != 0) // 홀수인 경우
    {
        i = len; // 자릿수 변수에 len 값 대입
        leftover = n; // 일단 n을 leftover에 대입
        while (leftover >= 10) // 마지막 한 자리 제외한 수 처리할 때
        {
            leftover = convert_top(leftover, i); // leftover 변수에 convert_top 반환값을 대입한다.
            i -= 2; // 처리가 끝난 자릿수 개수 삭제
        }
        if (leftover < 10) printf("*"); // 마지막 한 자리가 남은 경우 *를 출력시켜준다
    }
    else // 짝수인 경우
    {
        i = len; // 자릿수 변수에 len 값 대입
        leftover = n; // 일단 n을 leftover에 대입
        while (leftover != 0) //자릿수 처리하는 루프
        {
            leftover = convert_bottom(leftover, i); // leftover 변수에 convert_bottom의 반환값 대입
            i -= 2; // 처리가 끝난 자릿수 개수 삭제
        }
    }
    return 0;
}


int num_digit(int n) // 자릿수 개수 구하는 함수
{
    int cnt = 0; // 개수 저장하는 변수
    while (n != 0) // 자릿수 개수 구하는 루프
    {
        cnt++; // 개수 저장 변수에 더한다.
        n /= 10; // 처리가 끝난 자릿수 삭제
    }
    return cnt; // cnt를 반환
}

int convert_top(int n, int cnt) // 왼쪽부터 처리하는 함수
{
    int divider = 10; // 나누는 기기
    char result; // 변환된 결과 저장
    for (int i = 1; i < cnt - 2; i++)
        divider *= 10; // 자릿수보다 2자리 모자르기까지 10을 곱한다.
    result = n / divider; // 위에서 곱한 것으로 나눈 것을 저장

    if (result >= 'a' && result <= 'z' || result >= 'A' && result <= 'Z') // 대소문자인 경우 출력
        printf("%c", result);
    else // 대소문자가 아닌 경우
        printf("*"); // * 출력

    if (cnt - 2 <= 0) return 0; // 남은 자릿수가 없는 경우 + 1자릿수인 경우 0을 반환
    else return n % divider; // 그렇지 않은 경우 처리한 자릿수를 제거한 수를 반환
}

int convert_bottom(int n, int cnt) // 뒤쪽부터 먼저 변환하는 함수
{
    char result; // 결과값 저장 변수
    result = n % 100; // 끝 두자리 숫자 도출

    if (result >= 'a' && result <= 'z' || result >= 'A' && result <= 'Z') // 대소문자인 경우
        printf("%c", result); // 문자 출력
    else // 대소문자가 아닌 경우
        printf("*"); // * 반환
    if (cnt - 2 <= 0) return 0; // 남은 자릿수가 없는 경우 0을 반환
    else return n / 100; // 그렇지 않은 경우 처리한 자릿수 제거
}