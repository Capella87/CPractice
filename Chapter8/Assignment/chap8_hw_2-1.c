#include <stdio.h>
#define SIZE 10

char decrypt(char, int);

int main(void)
{
    int M; // 해독 키 저장 변수
    char encrypted[SIZE]; // 암호화된 문자를 저장하는 배열
    for (int i = 0; i < SIZE; i++)
        scanf("%c", &encrypted[i]); // 입력 받는다.
    scanf("%d", &M); // 복호화키 입력 받는다.
    for (int i = 0; i < SIZE; i++)
        printf("%c", decrypt(encrypted[i], M)); // 함수 호출 후 결과값 출력
    putchar('\n');
    return 0;
}

char decrypt(char ch, int M) // 복호화하는 함수
{
    char solved; // 복호화된 문자 변수
    M %= 26; // M이 26을 넘어가는 경우를 대비하기 위함
    if (ch >= 'a' && ch <= 'z') // 소문자인 경우
    {
        if (ch - M < 'a') // 뺀 값이 알파벳 범위를 벗어나는 경우
            solved = ch - M - 'a' + 'z' + 1; // 다시 z부터 시작하여 값을 구한다.
        else // 안 벗어나는 경우
            solved = ch - M; // 그냥 뺀다
        return solved; // 복호화된 값 반환
    }
    else if (ch >= 'A' && ch <= 'Z') // 대문자인 경우
    {
        if (ch - M < 'A') // 뺀 값이 알파벳 범위를 벗어나는 경우
            solved = ch - M - 'A' + 'Z' + 1; // 다시 Z부터 시작하여 값을 구한다.
        else // 안 벗어나는 경우
            solved = ch - M; // 그냥 뺀다
        return solved; // 복호화된 값을 반환
    }
    else
        return ch; // 복호화하지 않는다
}