#include <stdio.h>
#define SIZE 10

int main(void)
{
    int x[SIZE] = { 0, };
    int i = 0, j = 0, count = 0;

    for (i = 0; i < SIZE; i++)
        scanf("%d", &x[i]);
    for (i = 0; i < SIZE; i++)
    {
        count = 0;
        for (j = i + 1; j < SIZE; j++) // 해당 요소의 다음 요소부터 조사
            if (x[i] == x[j])
            {
                count++;
                x[j] = 0; // 중복된 요소 부분을 초기화
            }
        if (x[i] != 0)
            printf("%d %d\n", x[i], count + 1); // 위 루프에서 해당 요소를 제외하고 수를 세었기 때문에 보정된 값 (+1)을 출력한다.
    }

    return 0;
}