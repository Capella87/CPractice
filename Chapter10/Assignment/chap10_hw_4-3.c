#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(void)
{
    char str[SIZE], *pos = str; // 입력을 받을 문자열과 루프에서 사용할 포인터
    char op = '+'; // 연산 문자를 저장할 변수
    double numArr[10], result = 0.0; // 추출한 숫자를 저장할 배열과 결과를 출력할 변수
    size_t N; // 문자열의 크기를 저장할 변수
    int num = 0, numcount = 0; // 임시로 숫자를 저장할 변수와 저장된 숫자의 개수 변수

    scanf("%[^\n]", str); // 입력을 받는다.
    N = strlen(str); // 문자열의 길이를 구한다.
    for (; pos < str + N; pos++) // 널 문자 전까지 루프가 계속된다.
    {
        while (*pos == ' ' || *pos >= '0' && *pos <= '9') // 공백 문자와 숫자인 경우
        {
            if (*pos != ' ') // 숫자인 경우
                num = num * 10 + (int)(*pos - '0'); // 숫자 추출
            pos++; // 포인터 값 증가
        } // 이 아래에서는 위의 조건 외의 다른 문자를 만났을 때이다.
        if (op == '+') // 더하기인 경우
            numArr[numcount++] = (double)num; // 그냥 넣고 numcount를 증가시킨다.
        else if (op == '-') // 빼기인 경우
            numArr[numcount++] = (double)num * -1; // 음수로 바꿔서 넣는다.
        else if (op == '*') // 곱셈인 경우
            numArr[numcount - 1] *= (double)num; // 그 전 숫자에 곱해서 넣는다.
        else if (op == '/') // 나눗셈인 경우
            numArr[numcount - 1] /= (double)num; // 그 전 숫자에 나눠서 넣는다.
        num = 0; // 초기화
        if (*pos == '+' || *pos == '-' || *pos == '*' || *pos == '/') // 포인터가 가리키는 문자가 연산 문자인 경우
            op = *pos; // 새롭게 초기화
    }
    for (num = 0; num < numcount; num++) //출력하는 루프, num을 재활용했다.
        result += *(numArr + num); // 그냥 더한다.
    printf("%lf\n", result); // 출력한다.

    return 0;
}