#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct student // 학생 정보 저장 구조체
{
    char* studentName; // 학생 이름
    char id[5]; // 학생 학번
    char* subjectName; // 학생 과목명
    double subjectScore; // 과목 점수
} student;

int typeIn(student*, int); // 입력 함수
void sort(student*, int); // 정렬 함수
void errorExit(int); // 오류 처리 함수
int printDemand(student*, int, int); // 원하는 요소 출력


int main(void)
{
    int n, k;
    student* saved = NULL;

    scanf("%d", &n); // 입력 받는다.
    getchar();
    saved = (student*)malloc(sizeof(student) * n); // 동적 할당
    if (saved == NULL) // 제대로 할당이 안 된 경우 (메모리 부족)
        errorExit(ENOMEM); // 에러 처리 함수로 간다.
    if (typeIn(saved, n) != n) // 입력 함수에서 뭔가 문제가 생긴 경우; 입력을 덜 받았거나, 제대로 안 된 경우
        errorExit(EINTR); // 에러 처리 함수로 간다.
    sort(saved, n); // 정렬 함수
    scanf("%d", &k); // 원하는 순서 입력 받는다.
    printDemand(saved, k, n); // 함수 호출

    for (int i = 0; i < n; i++) // 메모리 반환
    {
        free(saved[i].studentName);
        free(saved[i].subjectName);
    }
    free(saved); // 본체 메모리 반환
    return 0;
}

int typeIn(student* input, int n) // 입력 함수
{
    student* pos = input; // 루프에서 사용할 변수
    char temp[101] = ""; // 임시 입력 버퍼
    
    for (; pos < input + n; pos++)
    {
        scanf("%s", temp); // 일단 입력을 받는다. 여기의 경우 학생 이름에 해당
        pos->studentName = (char*)malloc(sizeof(char) * (strlen(temp) + 1)); // 길이 측정 후 할당
        if (pos->studentName == NULL) // 메모리 부족 -> 오류 함수로
            errorExit(ENOMEM);
        strcpy(pos->studentName, temp); // 값 복사
        scanf("%s %s %lf", pos->id, temp, &pos->subjectScore); // 다른 값을 입력 받는다. 실제로는 위에 것까지 전부 한 줄에 입력된다. 여기서 temp를 다시 활용한다.
        getchar(); // 개행 문자 제거
        pos->subjectName = (char*)malloc(sizeof(char) * (strlen(temp) + 1)); // 과목명 할당
        if (pos->subjectName == NULL) // 메모리 부족 -> 오류 함수
            errorExit(ENOMEM);
        strcpy(pos->subjectName, temp); // 값 복사
    }

    return (int)(pos - input); // 처리한 개수 반환
}

void sort(student* target, int size) // 정렬 함수
{
    int i, j; // 루프에서 사용
    student temp; // 버퍼 역할

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if ((target + j)->subjectScore < (target + j + 1)->subjectScore) // 뒤에 더 큰 점수를 가진 자가 존재하는 경우
            {
                temp = *(target + j); // 버퍼 역할에 대입
                *(target + j) = *(target + j + 1); // swap
                *(target + j + 1) = temp; // swap
            }
        }
    }
}

void errorExit(int errcode) // 오류가 난 경우를 처리하는 함수
{
    printf("ERROR %d - ", errcode); // 오류 코드를 띄운다.
    switch (errcode) // 무슨 오류코드를 받았느냐에 따라 추가로 띄우는 메시지가 달라진다.
    {
    case EINTR:     // 함수에 뭔가 문제가 생긴 경우
        puts("Inturrupted function");
        break;
    case ENOMEM:   // 메모리 부족
        puts("Not enough memory");
        break;
    case EINVAL:  // argument가 맞지 않는 경우; 이 코드에서는 범위에 벗어나는 값을 k에 입력한 경우이다.
        puts("Invalid argument");
        break;
    default: 
        break;
    }
    printf("Search this error code on Microsoft Docs for details."); // MS docs의 errno 페이지에 오류가 정리되어 있으니 참조하라.
    // 추가 메시지; 위에 언급되지 않은 오류의 경우 이것만 출력된다.
    exit(EXIT_FAILURE); // 강제로 종료
}

int printDemand(student* input, int demand, int size) // 원하는 순서 인쇄
{
    if (demand - 1 >= size || demand - 1 < 0) // 범위를 벗어난 경우 에러
        errorExit(EINVAL);
    student* pos = input + demand - 1; // 번째와 실제 idx와의 차이 반영
    printf("%s %s %s %.2lf\n", pos->studentName, pos->id, pos->subjectName, pos->subjectScore); // 출력

    return 0;
}
