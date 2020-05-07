#include <stdio.h>

int main(void)
{
    int n, threeCnt = 0;
    int j;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        j = i; // 원본 손상 방지를 위한 복제본 생성
        while (j != 0)
        {
            if (j % 10 == 3)
                threeCnt++;
            j /= 10;
        }
    }
    printf("%d\n", threeCnt);
    return 0;
}