#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct _word // 단어 저장
{
    char letters[21];
    int count;
} word;

typedef struct _temp // 한 줄마다 가장 많은 단어를 위한 구조체
{
    char letters[21];
    int count;
    int line;
} temp;

int chk(char*, size_t); // 대문자와 단어 수 측정
void errExit(int); // 에러 처리
temp separator(char*, word*, int, int); // 단어 추출 및 구조체에 저장
void printOut(temp*, int); // 가장 많이 나온 단어를 선별하고 출력

int main(void)
{
    char** nstr; // 줄 입력받은 것을 저장할 포인터
    word* wrd; // 단어 저장할
    temp* saved; // 각 줄에서 가장 많이 나온 단어를 저장할 곳
    int n, i, wcnt; // 각각 줄 수, 루프에서 사용할 변수, 단어 수 저장 변수
    char tmp[501] = ""; // 임시 저장 버퍼
    size_t len; // 문자열 길이

    scanf("%d", &n); // 줄 수를 입력 받는다.
    getchar();
    nstr = (char**)malloc(sizeof(char*) * n); // 동적 할당
    if (nstr == NULL) errExit(ENOMEM); // 에러시 처리 함수로 넘어감
    saved = (temp*)malloc(sizeof(temp) * n); // 동적 할당
    if (saved == NULL) errExit(ENOMEM); // 에러시 처리 함수로 넘어감
    for (i = 0; i < n; i++) // 줄 수만큼 루프
    {
        wcnt = 0; // 단어 수 일단 초기화
        scanf("%[^\n]", tmp); // 입력 받는다
        getchar();
        len = strlen(tmp); // 길이 저장
        nstr[i] = (char*)malloc(sizeof(char) * (len + 1)); // 한 줄을 위한 동적 할당
        if (nstr[i] == NULL) errExit(ENOMEM); // 메모리 할당 실패시 처리 함수로 넘어감
        strcpy(nstr[i], tmp); // 복사
        wcnt = chk(nstr[i], len); // chk 함수 반환값을 대입
        wrd = (word*)malloc(sizeof(word) * wcnt); // 단어 수만큼 할당
        if (wrd == NULL) errExit(ENOMEM);
        saved[i] = separator(nstr[i], wrd, wcnt, i); // 그 줄에서 가장 많이 나온 단어가 반환된 것을 대입
        free(wrd); // 할당 해제
    }
    printOut(saved, n); // 출력
    for (i = 0; i < n; i++) // 동적 할당 해제
        free(nstr[i]);
    free(nstr);
    free(saved);
    return 0;
}

int chk(char* input, size_t len) // 대문자를 소문자로 변환하고, 단어 개수 반환
{
    char* pos = input; // 루프 사용
    int wcnt = 0; // 단어 수

    for (; pos <= input + len; pos++)
    {
        if (*pos >= 'A' && *pos <= 'Z') // 대문자
            *pos += 32; // 변환
        if (*pos == ' ' || pos == input + len) // 문자열 끝이나 공백인 경우 단어 수 증가
            wcnt++;
    }

    return wcnt; // 단어 수 반환
}

temp separator(char* input, word* target, int wcnt, int line) // 단어를 분리해서 저장하고, 그 중 가장 많이 나온 문자열의 구조체를 반환한다.
{
    char* pos = input; // 루프에서 사용할 것
    int count = 0, i = 0; // 각각 단어 수와 스펠링 수 
    char tmp[21] = ""; // 임시 저장 장소
    temp rt = { .line = line, .count = 0 }; // 가장 많이 나온 단어를 저장할 구조체
    size_t len = strlen(input); // 입력 받은 문자열의 길이 대입

    for (; pos < input + len; pos++) // 루프
    {
        while ((*pos >= 'a' && *pos <= 'z') || (*pos >= '0' && *pos <= '9')) // 단어
            tmp[i++] = *pos++;
        if (i != 0) // 단어가 끝난 경우
        {
            tmp[i] = '\0'; // 문자열로 처리하기 위해 널 삽입
            strcpy((target + count)->letters, tmp); // 단어 복사
            (target + count)->count = 0; // 단어 수를 일단 0으로 초기화
            count++; // 단어 수 증가
            i = 0; // 단어 철자 수 초기화
        }
    }
    for (i = 0; i < wcnt; i++) // 단어 수 측정 루프
    {
        if ((target + i)->count == -1) continue; // 이미 처리한 경우로 그냥 넘어 간다.
        for (int j = i; j < wcnt; j++) // 자기 자신부터 끝까지 측정
        {
            if (strcmp((target + i)->letters, (target + j)->letters) == 0) // 같은 것이 나온 경우
            {
                (target + i)->count++; // 수 증가
                if (j != i) (target + j)->count = -1; // 자기 자신이 아니면 처리한 것에 -1을 대입해 루프에서 넘어가게 한다.
            }
        }
        if (i == 0 || rt.count < (target + i)->count) // 가장 빈도수가 높은 것 갱신할 때; 처음에 초기화 하는 것도 있다.
        {
            strcpy(rt.letters, (target + i)->letters); // 조건이 맞으면 복사
            rt.count = (target + i)->count; // 빈도수 대입
        }
    }
    
    return rt; // 값 반환
}

void printOut(temp* input, int n) // 여러 줄 중 가장 많이 나온 것 선별 후 출력
{
    temp* pos = input, *max = input; // 루프에서 사용할 것과 가장 많이 나온 것을 가리킬 포인터
    for (; pos < input + n; pos++) // 선별 루프
        if (pos->count > max->count) // 값 갱신; 더 많이 나온 것이 발견된 경우
            max = pos; // 값 갱신
    printf("%d %d %s\n", max->line, max->count, max->letters); // 결과 출력
}

void errExit(int code) // 에러 처리 함수
{
    switch (code) // 코드에 따라 달라진다.
    {
    case ENOMEM: // 메모리가 부족하여 할당하는 데 실패한 경우
        puts("Not Enough Memory"); // 에러 메시지 출력
        break;
    default: // 이 외의 경우
        puts("ERROR!");
        break;
    }

    exit(EXIT_FAILURE); // 종료
}