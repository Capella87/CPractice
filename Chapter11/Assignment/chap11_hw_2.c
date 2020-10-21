#include <stdio.h>
#include <string.h>
#define MAX 100

struct _bank
{
    int id; // ID
    int arrival_time; // 도착한 시간
    int service_time; // 서비스 시간
    int waiting_time; // 대기 시간
};

void waitingtime(struct _bank[], int); // 대기 시간을 구해 각 배열의 waiting_time에 저장하는 함수
double avgtime(struct _bank[], int); // 평균 대기 시간을 구해 반환하는 함수

int main(void)
{
    struct _bank people[MAX]; // 구조체 배열 선언
    int N, i; // 각각 개수와 루프에서 사용할 변수
     
    scanf("%d", &N); // 사람 수를 입력 받는다.
    getchar();
    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d", &people[i].id, &people[i].arrival_time, &people[i].service_time);
        // 각각 id, 도착 시간, 필요로 하는 서비스 시간을 입력 받는다.
        getchar(); // 버퍼 비우기
    }
    waitingtime(people, N); // waitingtime 함수를 호출하여 대기 시간을 기록한다.
    printf("%.2lf\n", avgtime(people, N)); // avgtime 함수를 호출해 반환된 평균 대기 시간을 출력한다.

    return 0;
}

void waitingtime(struct _bank guest[], int N)
{
    int i;
    int service_sum = 0;
    // 대기 시간 산출 공식을 보면 앞사람들의 서비스 시간이 누적되어 있는데,이를 응용하여 누적시킴으로서 서비스 시간을 계산할 때 일일히 계산하지 않게 할 수 있다. (동적 계획법)

    guest[0].waiting_time = 0; // 1등은 대기시간이 0이므로 미리 대입
    for (i = 1; i < N; i++) // 1등 다음부터 루프를 돌린다.
    {
        service_sum += guest[i - 1].service_time;
        // 밑줄에서 계산을 하기 전에 전 사람의 서비스 시간을 더한다. 이것은 누적된다.
        guest[i].waiting_time = service_sum - guest[i].arrival_time;
        // 대기 시간을 산출한다.
    }
}

double avgtime(struct _bank guest[], int N)
{
    double average = 0.0; // 반환할 변수
    for (int i = 0; i < N; i++, guest++) // 루프 시작;
        average += (double)guest->waiting_time; // average에 대기 시간을 일단 전부 더한다.
    average /= N; // 사람 수로 나누어 평균을 구한다.

    return average; // average 변수를 반환한다.
}
