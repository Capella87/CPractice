#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) // 앞부분에 있는 X 출력
                printf(" X");
            else if (i == n - j - 1) // 끝부분에 있는 X 출력; n - j - 1이 i와 같은 경우일때 X 출력
                printf(" X");
            else // 그 외의 경우는 그냥 O 출력
                printf(" O");
        }
        printf("\n");
    }
}