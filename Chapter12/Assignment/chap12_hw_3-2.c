#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

typedef struct subject // 학생이 입력한 과목 저장 구조체
{
    char* name;
    double score;
} subject;

typedef struct student // 학생 정보 구조체
{
    char* name;
    char id[5];
    int numSubject;
    struct subject* psub;
    double avg;
} student;

void typeIn(student*, int); // 입력 받는 함수
void sort(student*, int); // 정렬하는 함수
void printOut(student*, int, int); // 출력하는 함수
void errExit(int); // 에러 처리 함수

int main(void)
{
    int n, k; // 각각 사람 수와 몇번째 사람 값을 저장
    student* info = NULL; // 학생들 정보 저장 포인터

    scanf("%d", &n); // 입력
    getchar(); // 개행 문자 제거
    info = (student*)malloc(sizeof(student) * n); // 할당
    if (info == NULL) errExit(ENOMEM); // 오류가 생긴 경우 오류 처리 함수로
    typeIn(info, n); // 입력
    sort(info, n); // 정렬
    scanf("%d", &k); // k에 값을 입력 받는다.
    getchar();
    printOut(info, n, k); // 결과 값 출력


    for (int i = 0; i < n; i++) // 할당 해제 루프
    {
        for (int j = 0; j < info[i].numSubject; j++)  // 구조체 내 할당된 것 해제
            free(info[i].psub[j].name);
        free(info[i].psub); // 구조체 내 구조체 해제
        free(info[i].name); // 이름 해제
    }
    free(info); // 자체를 해제
    return 0;
}

void typeIn(student* info, int n)
{
    int i, spacecnt; // 각각 루프에 쓸 것과 공백 수이다.
    char* pos; // 루프에서 사용할 것
    double sum; // 총합을 저장
    size_t len; // 입력받은 문자열의 길이
    char temp[101]; // 문자열을 받을 버퍼 역할을 하는 것
    for (i = 0; i < n; i++) // n번 반복
    {
        spacecnt = 0; // 0으로 일단 초기화
        sum = 0.0; // 역시 0으로
        scanf("%[^\n]", temp); // 문자열을 받는다
        getchar(); // 개행 문자 제거
        pos = temp; // 맨 처음을 가리키게 한다.
        len = strlen(temp); // 길이 대입
        for (; pos < temp + len; pos++) // 공백 찾는 루프;
        {
            if (*pos == ' ') // 찾은 경우
            {
                *pos = '\0'; // \0로 바꿔버린다.
                spacecnt++; // 수 증가
            }
        }
        info[i].numSubject = (spacecnt - 2) / 2 + 1; // 과목 수를 구한다.
        pos = temp; // 다시 temp의 맨 앞을 가리키게 한다.
        info[i].name = (char*)malloc(sizeof(char) * (strlen(pos) + 1)); // 이름 부분 크기 만큼 할당한다. 공백을 \0로 대체했기 때문에 이름만 읽을 것이기 때문이다.
        if (info[i].name == NULL) errExit(ENOMEM);
        strcpy(info[i].name, pos); // 값 복사
        pos += strlen(pos) + 1; // 다음 부분으로 간다.
        strcpy(info[i].id, pos); // 학번 복사
        pos += strlen(pos) + 1; // 다음으로
        info[i].psub = (subject*)malloc(sizeof(subject) * info[i].numSubject); // 과목 수만큼 할당한다.
        if (info[i].psub == NULL) errExit(ENOMEM);
        for (int j = 0; j < info[i].numSubject; j++) // 과목 수만큼 처리
        {
            info[i].psub[j].name = (char*)malloc(sizeof(char) * (strlen(pos) + 1)); // 구조체 내 이름 부분 할당
            if (info[i].psub[j].name == NULL) errExit(ENOMEM);
            strcpy(info[i].psub[j].name, pos); // 값 복사
            pos += strlen(pos) + 1; // 다음으로
            info[i].psub[j].score = (double)atoi(pos); // 문자열을 double형으로 바꿔서 대입
            sum += info[i].psub[j].score; // 계산하기 위해 sum에 추가
            pos += strlen(pos); // 다음으로 가는데 이게 끝일수도 있으므로 일단은 문자가 끝난 바로 다음으로 일단 간다.
            if ((size_t)(pos - temp) < len) pos++; // temp의 끝이 아니면 한번 더 가고, 그렇지 않으면 멈춘다.
        }
        info[i].avg = sum / info[i].numSubject; // 평균 산출
    }
}

void sort(student* input, int n) // 정렬 함수
{
    student temp; // 임시 저장 변수
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++) // 정렬 루프
        {
            if (((input + j)->avg < (input + j + 1)->avg) || ((input + j)->avg == (input + j + 1)->avg && strcmp((input + j)->id, (input + j + 1)->id) > 0))
            { // 뒤에 것이 평균이 더 크거나, 평균은 같은데 뒷사람 학번이 더 낮은 경우 바꾼다.
                temp = *(input + j); // 임시 저장
                *(input + j) = *(input + j + 1); // 대입
                *(input + j + 1) = temp; // 대입 2
            }
        }
    }
}

void printOut(student* target, int n, int k) // 출력
{
    student* pos = target + k - 1; // k번째를 가리키게 초기화
    subject* max = (target + k - 1)->psub; // 일단 그 구조체 내 과목 구조체의 첫번째 요소를 가리키게 한다.

    for (int i = 0; i < pos->numSubject; i++) // 가장 잘 나온 과목을 색인한다.
    {
        if (pos->psub[i].score > max->score) // 더 큰 것이 나온 경우
            max = &pos->psub[i]; // 갱신
    }
    printf("%s %s %.2lf %s %.2lf\n", pos->name, pos->id, pos->avg, max->name, max->score); // 결과 출력
}

void errExit(int code) // 에러 처리 함수
{
    switch (code) // 코드에 따라 달라진다.
    {
    case ENOMEM: // 메모리가 부족하여 할당하는 데 실패한 경우
        puts("Not Enough Memory"); // 에러 메시지 출력
    default: // 이 외의 경우
        puts("ERROR!");
    }

    exit(EXIT_FAILURE); // 종료
}