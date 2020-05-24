#include <stdio.h>
#define SIZE 10

int main(void)
{
    int x[SIZE], i, temp, oddcount = 0, evencount = 0; // 변수 선언

    for (i = 0; i < SIZE; i++) // 입력 후 판별을 위한 루프
    {
        scanf("%d", &temp); // temp라는 변수에 값을 입력 받음
        if (temp % 2 == 0)
            x[SIZE - 1 - evencount++] = temp; // 짝수인 경우 뒤쪽에 temp 변수 값을 입력한 후 evencount에 1을 더함 (후치 수식)
        else
            x[oddcount++] = temp; // 홀수인 경우 앞쪽에 temp 변수 값을 입력한 후 oddcount에 1을 더함 (후치 수식)
    }
    for (i = 0; i < SIZE; i++) // 출력 루프
        printf("%d ", x[i]); // 출력
    putchar('\n');
    return 0;
    
}