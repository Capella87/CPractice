#include <stdio.h>
#define SIZE 100

char decrypt(char, int);
char encrypt(char, int);

int main(void)
{
    int M1, M2; // 해독 키 저장 변수
    char orig[SIZE]; // 암호화된 문자를 저장하는 배열
    char computed[SIZE]; // 복호화된 문자를 저장하는 배열
    int charcount = 0, i; // 문자 수 변수
    char ch; // 임시로 문자를 입력받는 변수

    while ((ch = getchar()) != '*') // *가 나올때까지 계속 문자를 입력받는다.
        orig[charcount++] = ch;
    scanf("%d %d", &M1, &M2);  // 복호화키와 암호화키를 받는다
    for (i = 0; i < charcount; i++) // 복호화 루프
    {
        computed[i] = decrypt(orig[i], M1); // 복호화한 문자를 새로운 배열에 저장한다.
        printf("%c", computed[i]); // 복호화된 문자 출력
    }
    putchar('\n');
    for (i = 0; i < charcount; i++) // 복호화한 문자를 다시 암호화하는 루프
        printf("%c", encrypt(computed[i], M2)); // 다시 암호화된 문자를 출력
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

char encrypt(char ch, int M) // 암호화 함수
{
    char secret; // 암호화된 문자 저장 변수
    M %= 26; // 위에서 언급한 대로 26보다 키가 큰 경우를 위함
    if (ch >= 'a' && ch <= 'z') // 소문자
    {
        if (ch + M > 'z') // 암호화키를 문자에 더한 값이 소문자 영역 밖으로 나갈 경우
            secret = ch + M - 'z' - 1 + 'a'; // 보정
        else // 위의 경우가 아닌 경우
            secret = ch + M; // 그냥 더해서 구한다.
        return secret; // 암호화된 문자를 반환
    }
    else if (ch >= 'A' && ch <= 'Z') // 대문자
    {
        if (ch + M > 'Z') // 암호화키를 문자에 더한 값이 대문자 영역 밖으로 나갈 경우
            secret = ch + M - 'Z' - 1 + 'A'; // 보정
        else // 위의 경우가 아닌 경우
            secret = ch + M; // 그냥 더해서 구한다.
        return secret; // 암호화된 문자를 반환
    }
    else // 대소문자가 아닌 경우
        return ch; // 암호화 처리하지 않고 그냥 반환
}