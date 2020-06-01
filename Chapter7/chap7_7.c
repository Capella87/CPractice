#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

int main(void)
{
    int x[SIZE]; // 입력받은 숫자를 저장할 배열
    int i, j, count; // 같은 숫자를 세기 위한 count 변수
    bool flag; // 중복된 숫자 구별을 위한 스위치

    for (i = 0; i < SIZE; i++) // 입력 받는 루프
        scanf("%d", &x[i]);
    for (i = 0; i < SIZE; i++) // 같은 숫자를 세고, 결과값을 출력하는 루프
    {
        count = 0; // 0으로 초기화한다.
        flag = false; // flag를 거짓(false)으로 초기화한다.
        for (j = 0; j < i; j++) // 해당 i + 1번째 배열 요소와 이미 같은 요소를 찾아내는 루프
            if (x[j] == x[i]) // 해당 요소 이전에 이미 중복된 수가 있는 경우를 찾아내기 위함
            {
                flag = true; // flag 값을 1로 바꾼다.
                break; // 단순히 중복되는 수가 있느냐만 따지기 때문에 flag = true이면 그 이후부터는 따질 필요가 없다.
            }
        if (flag) continue; // 이전에 중복된 수가 있는 경우에는 아랫 과정을 생략한다.
        for (j = i; j < SIZE; j++) // 해당 요소와 그 이후 배열 요소를 대조한다.
            if (x[j] == x[i]) count++; // 중복된 수가 나오는 경우 카운트를 증가시킨다.
        printf("%d %d\n", x[i], count); // 해당 요소와 개수를 출력한다.
    }

    return 0;
}