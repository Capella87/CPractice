#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

struct hotel_info // 호텔 정보 저장 구조체
{
    char name[31]; // 이름
    int grade; // 등급
    double rating; // 평점
    double distance; // 거리
    char breakfast; // 조식 제공 여부
};

int in_hotel_info(struct hotel_info*); // 입력받는 함수
void out_hotel_info(struct hotel_info*, int, int, double); // 사용자가 원하는 호텔을 선정해 보여주는 함수

int main(void)
{
    struct hotel_info list[MAX]; // 호텔 정보 저장할 구조체 배열
    int num = in_hotel_info(list); // 호텔 개수를 반환한 것을 num에 저장
    int searchGrade; // 사용자가 원하는 최소 등급
    double searchDist; // 사용자가 원하는 최대 거리

    scanf("%d %lf", &searchGrade, &searchDist); // 최소 등급과 최대 거리를 입력 받는다.
    out_hotel_info(list, num, searchGrade, searchDist); // 함수 호출

    return 0;
}

int in_hotel_info(struct hotel_info* p)
{
    char temp[31]; // 임시로 입력 받을 함수
    int count = 0; // 입력 받은 호텔 개수
    struct hotel_info* pos = p; // 루프에서 사용할 포인터

    for (; pos < p + MAX; pos++) // 100개 입력 전까지 루프를 돌린다. 100이 되면 자동 종료
    {
        scanf("%s", temp); // 일단 입력 받는다.
        if (strcmp(temp, "0") == 0) // 0을 입력받은 경우
        {
            while (getchar() != '\n') // 오작동을 막기 위해 버퍼를 비운다.
                continue;
            break; // 루프 탈출
        }
        strcpy(pos->name, temp); // 저 조건이 아닌 경우 name 멤버로 복사
        scanf("%d %lf %lf %c", &pos->grade, &pos->rating, &pos->distance, &pos->breakfast); // 다른 값들을 입력 받는다.
        // 실제로는 제목을 포함해 한 줄에 걸쳐 입력을 받는데, 위 조건에 안 걸린 경우 버퍼를 비우지 않았기 때문에 있는 순서대로 처리할 것이다.
        getchar(); // 개행 문자가 남아 있을 것인데, 이를 제거
        count++; // 개수 카운터 증가
    }

    return count; // 개수 반환
}

void out_hotel_info(struct hotel_info* p, int N, int G, double D)
{
    struct hotel_info* pos = p; // 루프에서 사용할 포인터이다
    struct hotel_info saved[MAX], temp; // 조건에 맞는 구조체를 저장하는 구조체 배열과 소팅에서 임시로 저장하기 위한 구조체 변수 
    int sufCount = 0; // 조건에 맞는 구조체 개수
    bool f = false; // 처음 조건에 걸린 경우를 구분하기 위한 bool 변수

    for (pos = p; pos < p + N; pos++) // 개수만큼 루프를 돌린다.
    {
        if (pos->grade >= G && pos->distance <= D) // 조건에 맞는 게 나온 경우
            *(saved + sufCount++) = *pos; // saved 배열에 저장 후 sufCount 후치연산
    }
    for (int i = 0; i < sufCount - 1; i++) // 버블 소팅
    {
        for (pos = saved; pos < saved + sufCount - 1 - i; pos++)
        {
            if (pos->rating < (pos + 1)->rating || (pos->rating == (pos + 1)->rating && strcmp(pos->name, (pos + 1)->name) > 0)) // 평점 내림차순으로 정렬하되, 평점이 같은 경우 사전순으로 배열한다.
            {
                temp = *pos; // 일단 임시로 저장
                *pos = *(pos + 1); // 스왑
                *(pos + 1) = temp; // 임시로 저장한 값 불러온다.
            }
        }
    }
    for (pos = saved; pos < saved + sufCount; pos++) // 출력
        printf("%s %d %.1lf %.1lf %c\n", pos->name, pos->grade, pos->rating, pos->distance, pos->breakfast);
}