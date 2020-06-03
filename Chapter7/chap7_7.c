#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

int main(void)
{
    int x[SIZE];
    int i, j, count;
    bool flag;

    for (i = 0; i < SIZE; i++)
        scanf("%d", &x[i]);
    for (i = 0; i < SIZE; i++)
    {
        count = 0;
        flag = false;
        for (j = 0; j < i; j++) // 현재 조사 중에 있는 배열 이전 요소까지 중복 검사
            if (x[j] == x[i]) // 중복된 요소가 나온 경우
            {
                flag = true;
                break;
            }
        if (flag) continue; // 플래그가 1인 경우 아래 과정 생략
        for (j = i; j < SIZE; j++) // 해당 요소부터 배열 끝까지 돌리는 루프
            if (x[j] == x[i]) count++; // 같은 요소가 나온 경우 count 변수에 1씩 더한다.
        printf("%d %d\n", x[i], count); // count 변수 출력
    }

    return 0;
}