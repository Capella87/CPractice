#include <stdio.h>
#include <string.h>

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
    char who[SIZE]; // 검색어를 저장할 문자열
    int i; // 루프에서 사용할 

    for(i = 0; i < PEOPLE; i++) // 학생들의 정보를 입력 받는다.
        scanf("%s %s %c", info[i].name, info[i].stuNum, &info[i].avgCredit);
    getchar();
    scanf("%[^\n]", who); // 검색어를 입력 받는다.
    for (i = 0; i < PEOPLE; i++) // 찾는 루프
    {
        if (strcmp(who, info[i].name) == 0) // 검색어와 일치하는 것을 찾았을 때
        {
            printf(" %s %c\n", info[i].stuNum, info[i].avgCredit); // 출력
            break; // 루프 종료
        }
    }

    return 0;
}
