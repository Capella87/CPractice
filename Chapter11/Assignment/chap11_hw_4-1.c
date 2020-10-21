#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 100

struct CarLog // 출입 정보를 저장하는 구조체
{
    int carid; // 차량 번호
    char studentID[7]; // 학번
    char enterDate[11]; // 입차 년월일
    char enterTime[6]; // 입차 시간
    char exitDate[11]; // 출차 년월일
    char exitTime[6]; // 출차 시간
};

int eventInput(struct CarLog*, int); // 이벤트를 입력받는 함수
void findViolence(struct CarLog*, int); // 부정 사용자들을 적발하는 함수

int main(void)
{
    int N; // 입력할 횟수
    struct CarLog data[MAX]; // 출입 기록 저장 구조체 배열

    scanf("%d", &N); // 입력 받을 횟수를 입력 받는다.
    getchar(); // 버퍼 내 개행 문자 제거
    eventInput(data, N); // 이벤트 입력 함수 호출
    findViolence(data, N); // 부정 사용자 적발 함수 호출

    return 0;
}

int eventInput(struct CarLog* input, int N)
{ // 이벤트를 입력 받는 함수
    int i; // 루프에서 사용할 지역 변수 (auto variable)

    for (i = 0; i < N; i++) // 입력 루프
    {
        scanf("%d %s %s %s %s %s", &(input + i)->carid, &(input + i)->studentID, &(input + i)->enterDate, &(input + i)->enterTime, &(input + i)->exitDate, &(input + i)->exitTime);
        getchar(); // 정보를 입력 받고 버퍼 내 개행 문자를 다음 입력을 위해 제거
    }

    return i; // 입력 받은 개수 반환; 응용하면 N과 일치하지 않은 경우 에러 메시지를 띄울 수 있을 것이다.
}

void findViolence(struct CarLog* input, int N) // 부정 사용자들을 적발하는 함수
{
    bool status[MAX] = { false, }, dup = false;
    // 첫번째 배열의 경우 중복될 경우 true로 하여 다시 검사하지 않게 하고, 두번째의 경우 2대를 초과해서 나오는 경우를 위한 변수이다.
    int count = 0; // 부정 사용자 수를 세는 변수
    struct CarLog violators[MAX], temp; // 부정 사용자를 저장하는 구조체 배열과 소팅에서 사용할 임시 변수이다.
    struct CarLog* pos = input, * pos2; // 둘 다 루프에서 사용할 구조체 포인터이다.

    for (; pos < input + N; pos++) // 적발하는 루프
    {
        if (*(status + (pos - input)) == true) // 중복된 것이 나온 경우 패스
            continue;
        dup = false; // dup = false로 초기화
        for (pos2 = pos; pos2 < input + N; pos2++) // pos가 가리키는 구조체 부분과 pos2를 사용한 다른 구조체 요소 대조
        {
            if (strcmp(pos->studentID, pos2->studentID) == 0 && pos->carid != pos2->carid && pos != pos2) // 자기 자신이 아니고 학번과 차량번호가 일치한 경우
            {
                status[pos2 - input] = true; // pos와 중복되므로 true로 변경
                if (!dup) // pos가 가리키는 자의 부정 사용이 처음 적발된 경우
                {
                    violators[count++] = *pos; // 부정 사용자를 저장하는 구조체에 기록 후 카운트 후치 연산
                    dup = true; // 단순히 기록만 하는 것이므로 이후에 나와도 이 조건문을 지나지 않게 true로 값을 바꾼다.
                }
            }
        }
    }
    for (int i = 0; i < count - 1; i++) // 부정 사용자들을 저장한 구조체를 학번 오름차순으로 배열하는 루프
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (strcmp(violators[j].studentID, violators[j + 1].studentID) > 0)
            { // 후자가 전자보다 학번이 높은 경우
                temp = violators[j]; // 임시 저장
                violators[j] = violators[j + 1]; // 스왑
                violators[j + 1] = temp; // 변경 완료
            }
        }
    }

    for (int i = 0; i < count; i++) // 부정 사용자들의 학번을 출력하는 루프
        puts(violators[i].studentID); // 출력
}
