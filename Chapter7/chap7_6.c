#include <stdio.h>
#define SIZE 3

int main(void)
{
    char answer[SIZE];
    char status[SIZE] = { '_', '_', '_' }; // 일단 블랭크로 처리하기 위해 미리 값을 입력해 두었다.
    int i, count = 1; // count -> 시도 횟수
    char ch; // 일단 문자를 입력받을 변수

    for (i = 0; i < SIZE; i++) // 정답을 입력받는 루프
        scanf("%c", &answer[i]);
    getchar();

    while (count <= 5)
    {
        scanf("%c", &ch);
        getchar(); // 개행 문자를 받아서 버리는 용도
        for (i = 0; i < SIZE; i++) // 정답과 대조하는 루프
        {
            if (ch == answer[i]) // 맞춘 경우
                status[i] = ch; // status 배열에 ch 값 대입
            else
                continue;
        }
        for (i = 0; i < SIZE; i++)
            printf(" %c", status[i]); // 맞춘 상태 출력
        putchar('\n');
        count++; // 시도 횟수 증가
        if (status[0] != '_' && status[1] != '_' && status[2] != '_') // 전부 다 맞춘 경우 종료한다.
            break;
    }
    return 0;
}