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
int findViolence(struct CarLog*, struct CarLog*, int); // 부정 사용자들을 적발하여 구조체로 반환하는 함수
int tollCalc(struct CarLog*, struct CarLog*, int, int, const int); // 요금 계산 함수; 요금을 반환한다.
int timeCalc(struct CarLog*); // 시간 계산 함수; 계산된 시간을 분 단위로 반환한다.

int main(void)
{
    int N, N2; // 입력할 횟수
    struct CarLog data[MAX]; // 출입 기록 저장 구조체 배열
    struct CarLog violators[MAX];
    int vCount = 0, carinput;

    scanf("%d", &N); // 입력 받을 횟수를 입력 받는다.
    getchar(); // 버퍼 내 개행 문자 제거
    eventInput(data, N); // 이벤트 입력 함수 호출
    vCount = findViolence(data, violators, N); // 부정 사용자 적발 함수 호출
    scanf("%d", &N2); // 조회할 횟수를 입력 받는다.
    getchar(); // 개행 문자 제거
    for (int i = 0; i < N2; i++) // N2만큼 루프를 돌린다.
    {
        scanf("%d", &carinput); // 차 번호를 입력 받는다.
        getchar();
        printf("%d\n", tollCalc(data, violators, N, vCount, carinput)); // tollCalc를 호출해 반환된 값을 춝력한다.
    }

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

int findViolence(struct CarLog* input, struct CarLog* violators, int N) // 부정 사용자들을 적발하는 함수
{
    bool status[MAX] = { false, }, dup = false;
    // 첫번째 배열의 경우 중복될 경우 true로 하여 다시 검사하지 않게 하고, 두번째의 경우 2대를 초과해서 나오는 경우를 위한 변수이다.
    int count = 0; // 부정 사용자 수를 세는 변수
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
                    *(violators + count++)= *pos; // 부정 사용자를 저장하는 구조체에 기록 후 카운트 후치 연산
                    dup = true; // 단순히 기록만 하는 것이므로 이후에 나와도 이 조건문을 지나지 않게 true로 값을 바꾼다.
                }
            }
        }
    }

    return count;
}

int tollCalc(struct CarLog* data, struct CarLog* violators, int N, int vN, const int input) // 요금을 계산하는 함수
{
    int fee = 0, time = 0; // 각각 청구된 요금, 주차 시간을 저장하는 함수이다.
    struct CarLog* pos = data; // 루프에서 사용할 포인터
    while (pos->carid != input && pos - data < N) // 검색해서 같은 것이 나오면 멈춘다.
        pos++;
    time = timeCalc(pos); // timeCalc 함수를 호출해 총 시간을 반환받아 대입한다.
    
    if (time <= 60) // 1시간까지인 경우
        fee = 3000; // 기본 요금
    else // 1시간 초과
    {
        fee = 3000 + ((time - 60) / 10) * 1000; // 기본 요금에 더해, 10분으로 나누어 일단 값을 계산한다.
        if (((time - 60) % 10) != 0) // 1분이라도 초과하면 올림 처리를 해야 하기 때문에 있는 조건
            fee += 1000; // 올림
    }
    if (fee > 30000) fee = 30000; // 총합이 30000원을 초과한 경우 30000원으로 변경
    for (int i = 0; i < vN; i++) // 위반한 자인지 여부를 조사한다.
    {
        if (strcmp((violators + i)->studentID, pos->studentID) == 0) // 위반한 사람인 경우
        {
            fee = 100000; // 벌금을 물린다.
            break; // 루프 탈출
        }
    }

    return fee; // 요금을 반환한다.
}

int timeCalc(struct CarLog* input) // 시간 계산 함수
{
    int total = 0, temp1 = 0, temp2 = 0; // 총 시간 변수와 루프에서 임시로 값을 저장할 때 쓰이는 두 변수이다.

    for (int i = 0; i < 5; i++) // 시간 포맷이어서 5번 반복이고, 입차 시간과 출차 시간을 동시에 검사한다.
    {
        if (i != 2) // :가 아닌 그냥 숫자일 때
        {
            temp1 = temp1 * 10 + (int)(input->enterTime[i] - '0'); // temp1은 입차 시간을 처리하는 변수로, 자릿값을 추출해서 넣는다.
            temp2 = temp2 * 10 + (int)(input->exitTime[i] - '0'); // temp2는 출차 시간을 처리하는 변수로, 자릿값을 추출해서 넣는다.
        }
        else // :인 경우
        {
            total = temp2 * 60 - temp1 * 60; // 출차 시간에서 입차 시간을 뺀다. 분을 처리할 때는 음수가 나올 수도 있다.
            temp1 = 0; // 시간 부분을 처리하고 나서 분을 처리하기 위해 초기화
            temp2 = 0; // 위와 같다.
        }
    }
    total += temp2 - temp1; // 최종적으로 산출
    
    return total; // 산출된 시간 반환
}
