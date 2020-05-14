#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);
    int i = 0, j = 0;

    while (i < n)
    {
        for (j = 1; j <= n; j++)
            printf(" %d", (i + j) % 10); // 숫자 출력; 첫번째 부분에서 줄 번호에 맞게 출력, 10이 넘는 경우 0으로 출력
        printf("\n");
        i++;
    }
    return 0;

}