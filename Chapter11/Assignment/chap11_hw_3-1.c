#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
    struct hotel_info list[100]; // 호텔 정보 저장할 구조체 배열
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

    for (; pos < p + 100; pos++) // 100개 입력 전까지 루프를 돌린다. 100이 되면 자동 종료
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
    struct hotel_info* best = p, *pos = p; // 각각 조건에 맞는 구조체를 가리킬 포인터와 루프에서 사용할 포인터이다. 전자의 경우 일단 첫번째를 가리키도록 했다.
    bool f = false; // 처음 조건에 걸린 경우를 구분하기 위한 bool 변수

    for (pos = p; pos < p + N; pos++) // 개수만큼 루프를 돌린다.
    {
        if (pos->grade >= G && pos->distance <= D) // 조건에 맞는 게 나온 경우
        {
            if (!f) // 위에서 초기화 된 이후 바뀐 적이 없는 경우
            {
                best = pos; // 초기화
                f = true; // 스위치 활성화로 이 조건으로 오지 못하게 한다.
            }
            else if (best->rating < pos->rating) // f == true인데 rating이 기존 best보다 좋은 경우 초기화
                best = pos;
            else if (best->rating == pos->rating && strcmp(best->name, pos->name) > 0) // rating도 같은 경우 사전순으로 먼저 오는 것으로 초기화
                best = pos;
        }
    }
    printf("%s %d %.1lf %.1lf %c\n", best->name, best->grade, best->rating, best->distance, best->breakfast); // 결과 출력
}