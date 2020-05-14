#include <stdio.h>

int main(void)
{
    int m, n, cnt = 0, divisor = 0;

    scanf("%d %d", &m, &n);

    for (int i = (m < n ? m : n); i <= (m < n ? n : m); i++) // 삼항연산자를 쓸 때에는 반드시 묻는 식이 같아야 한다.
    {
        divisor = 0;
        for (int j = 1; j <= i; j++) // j는 반드시 1이어야 한다.
        {
            if (i % j == 0)
                divisor++;
        }
        if (divisor % 2 == 0)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}