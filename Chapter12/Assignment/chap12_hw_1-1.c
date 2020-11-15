#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct st // 저장하기 위한 구조체
{
    char* str;
    int cnt;
} st;

int typeIn(st*, int); // 값을 입력받는 함수
int cntConso(char*, size_t); // 자음 세는 함수
int printOut(st*, int); // 출력 함수
void sort(st*, int); // 정렬 함수
int freeElmt(st*, int); // 메모리 해제 함수

int main(void)
{
    st* saved = NULL; // 동적할당 때 사용
    int n; // case 개수

    scanf("%d", &n); // 입력 받는다.
    getchar(); // 개행 문자 제거
    saved = (st*)malloc(sizeof(st) * n); // 동적 할당
    typeIn(saved, n); // 입력 함수로 입력 받는다.
    sort(saved, n); // 정렬
    printOut(saved, n); // 출력
    freeElmt(saved, n); // 메모리 해제
    return 0;
}

int typeIn(st* input, int size) // 입력받는 함수
{
    st* pos = input; // 루프에서 사용할 포인터
    char temp[MAX + 1] = ""; // 임시로 값을 받을 배열

    for (; pos < input + size; pos++) // 입력 루프
    {
        scanf("%[^\n]", temp); // temp에 일단 임시로 입력 받는다.
        getchar(); // 개행 문자 제거
        pos->str = (char*)malloc(sizeof(char) * (strlen(temp) + 1)); // 동적 할당; null 문자 때문에 1개 더 할당
        strcpy(pos->str, temp); // 값 복사
        pos->cnt = cntConso(pos->str, strlen(pos->str)); // 자음 세는 문자 호출 후 반환 값 대입
    }
    return (int)(pos - input) + 1;
}

int cntConso(char* input, size_t len) // 자음 세는 함수
{
    char* pos = input; // 루프 사용 포인터
    int cnt = 0; // 자음 개수

    for (; pos < input + len; pos++)
        if (*pos != 'A' && *pos != 'I' && *pos != 'U' && *pos != 'E' && *pos != 'O' && *pos != 'a' && *pos != 'i' && *pos != 'u' && *pos != 'e' && *pos != 'o')
            cnt++; // 모음이 아니면 (==자음이면) 증가
    return cnt; // 자음 개수 반환
}

void sort(st* input, int n) // 정렬하는 함수
{
    int i, j; // 루프에서 사용할 것
    st temp; // 정렬 때 임시로 저장할 변수

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if ((input + j)->cnt < (input + j + 1)->cnt) // 뒤에 있는 문자열의 자음 개수가 더 큰 경우 swap
            {
                temp = *(input + j + 1); // 임시 저장
                *(input + j + 1) = *(input + j); // 대입
                *(input + j) = temp; // 임시 저장값 대입
            }
        }
    }
}

int printOut(st* target, int n) // 출력 함수
{
    st* pos = target;

    for (; pos < target + n; pos++) // 출력 루프
        puts(pos->str);
    return (int)(pos - target) + 1;
}

int freeElmt(st* target, int n) // 메모리 해제 함수
{
    st* pos = target;

    for (; pos < target + n; pos++)
        free(pos->str); // 문자열 동적 할당 해제
    free(target); // 구조체 포인터 동적 할당 해제
    return 0;
}