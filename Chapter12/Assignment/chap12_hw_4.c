#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef char placetype; // 편의를 위한 정의
typedef char date;
typedef int errcode;

typedef struct spots // 관광명소 등록 구조체
{
    char name[21]; // 명소명
    int fee; // 가격
    placetype ptype; // 명소 유형
    date date[9]; // 오픈 일시
    char cityname[30]; // 소재 도시명
} PLACE;

typedef struct city // 도시 구조체
{
    char name[30]; // 도시명
    int num; // 등록된 명소 수
} CITY;

int typeIn(CITY*, PLACE**, int); // 입력 함수 
void errorExit(errcode); // 에러 대처 함수
PLACE* Costly(CITY*, PLACE**, int); // 가장 비싼 관광지 찾는 함수

int main(void)
{
    int n, i;
    CITY* list = NULL;
    PLACE** spots = NULL; // 이것들은 전부 동적 할당에 쓰일 것들이다.
    PLACE* max = NULL; // 이것은 가장 비싼 관광지를 찾는 함수가 반환한 값을 저장할 포인터 변수

    scanf("%d", &n); // 도시 수를 입력 받는다.
    getchar();
    list = (CITY*)malloc(sizeof(CITY) * n); // 도시 수만큼 할당한다.
    if (list == NULL) errorExit(ENOMEM); // 메모리가 부족한 경우 빠져나간다.
    spots = (PLACE**)malloc(sizeof(PLACE*) * n); // 도시 수만큼 일단 할당
    if (spots == NULL) errorExit(ENOMEM); // 메모리가 부족한 경우 빠져나간다.
    typeIn(list, spots, n); // 입력 함수
    max = Costly(list, spots, n); // 가장 높은 입장료를 가진 것을 가리키게 함
    printf("%s %s %d %s %c\n", max->cityname, max->name, max->fee, max->date, max->ptype); // 출력

    for (i = 0; i < n; i++) // 메모리 해제
        free(spots[i]);
    free(spots);
    free(list);
    return 0; // 끝
}

int typeIn(CITY* cities, PLACE** spots, int ccount) // 입력 받는 함수
{
    int i, j; // 루프에서 사용할 변수
    for (i = 0; i < ccount; i++) // 도시 이름을 일단 입력 받는다.
        scanf("%s", (cities + i)->name);
    getchar();
    for (i = 0; i < ccount; i++) // 저장할 관광지 수
    {
        scanf("%d", &(cities + i)->num); // 입력 받는다.
        spots[i] = (PLACE*)malloc(sizeof(PLACE) * (cities + i)->num); // 수만큼 할당한다.
        if (spots[i] == NULL) errorExit(ENOMEM); // 메모리 부족의 경우 '도망'간다.
    }
    getchar();
    for (i = 0; i < ccount; i++) // 여기서는 관광지 정보를 입력 받는다.
    {
        for (j = 0; j < (cities + i)->num; j++)
        {
            scanf("%s %d %c %s", spots[i][j].name, &spots[i][j].fee, &spots[i][j].ptype, spots[i][j].date); // 관광지 이름, 입장료, 유형, 오픈 일자를 입력 받는다.
            strcpy(spots[i][j].cityname, (cities + i)->name); // 관광지 소재 도시이름 복사
            getchar();
        }
    }
    return 0;
}

PLACE* Costly(CITY* data, PLACE** target, int n) // 가장 입장료가 비싼 것 도출하는 함수
{
    PLACE* max = *target; // 루프에서 사용할 것, 일단은 맨 처음 원소를 가리키게 한다.
    int i, j;

    for (i = 0; i < n; i++) // 루프
        for (j = 0; j < (data + i)->num; j++)
            if (target[i][j].fee > max->fee || (target[i][j].fee == max->fee && strcmp(target[i][j].date, max->date) < 0)) // 입장료가 더 비싸거나, 입장료는 같은데 오픈 일자가 오래된 경우
                max = &target[i][j]; // 갱신

    return max; // 가리키는 것 반환
}

void errorExit(errcode code) // 오류 대처 함수
{
    switch (code) // 무슨 코드를 받았는지에 따라 나뉘어진다. (나의 경우 errno.h를 참조하여, 메모리 부족의 경우 ENOMEM으로 처리하였다.)
    {
    case ENOMEM: // 메모리가 부족한 경우
        puts("Not Enough Memory."); // 에러 이유를 띄운다.
        break;
    default: // 그 외의 경우
        break;
    }

    exit(EXIT_FAILURE); // 바로 프로그램을 종료하며, EXIT_FAILURE는 stdlib.h에 정의되어 있는 상수로 프로그램에 에러가 생겼다는 것을 exit에 대입 한 후 프로그램을 묻지도 따지지도 않고 종료한다.
}