#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 10
#define PEOPLE 5

struct student // student 구조체 선언
{
    char name[SIZE]; // 이름을 저장하는 멤버
    char stuNum[SIZE + 1]; // 학번을 저장하는 멤머
    char avgCredit; // 지난학기 평균 학점을 저장하는 문자형의 멤버
};

int main(void)
{
    struct student info[PEOPLE]; // 구조체 배열 선언
    struct student *keyword = NULL; // 검색어와 이름이 같은 구조체를 가리킬 포인터
    char who[SIZE]; // 검색어를 저장할 문자열
    int i; // 루프에서 사용할
    bool flag = false; // 검색어를 찾고 나서 해당 학생의 입학년도를 복사하는 루틴을 위한 플래그 변수
    bool match = false; // 조건과 일치하지 않아 계속 false인 경우 밑에서 0을 출력할 수 있게 해주는 플래그 변수

    for (i = 0; i < PEOPLE; i++) // 학생들의 정보를 입력 받는다.
        scanf("%s %s %c", info[i].name, info[i].stuNum, &info[i].avgCredit);
    getchar();

    scanf("%[^\n]", who); // 검색어를 입력 받는다.
    for (i = 0; i < PEOPLE; i++) // 찾는 루프
    {
        if (!flag && strcmp(who, info[i].name) == 0) // 검색어와 일치하는 것을 찾았을 때
        {
            keyword = &info[i]; // 해당 구조체를 가리키게 한다.
            flag = true; // true로 바꾸어 다시는 이 조건으로 들어오지 않게 한다.
            i = -1; // 루프 처음으로 돌린다.
            continue;
        }
        if (flag && strcmp(keyword->name, info[i].name) != 0 && strncmp(keyword->stuNum, info[i].stuNum, 4) == 0 && keyword->avgCredit == info[i].avgCredit)
        { // flag가 true이고, 이름은 다르면서 입학한 연도와 지난학기 평균 학점이 같은 경우
            match = true; // 한번이라도 나왔으므로 true로 바꾼다.
            printf(" %s\n", info[i].name); // 해당 조건을 만족하는 구조체에 있는 이름 출력
        }
    }
    if (!match) // 일치한 것이 한 개도 안 나온 경우
        printf("0\n"); // 0을 출력한다.

    return 0;
}