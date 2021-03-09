#include <stdio.h>

int main(void)
{
    int m, n;
    int total = 0, cnt = 0;

    scanf("%d %d", &m, &n);

    int i = n < m ? n : m;
    do
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
            cnt++;
            total += i;
        }
        i++;
    } while (i <= (n < m ? m : n));
    printf("cnt=%d sum=%d\n", cnt, total);
    i = n < m ? n : m; cnt = 0; total = 0;
    do
    {
        if (i % 3 == 0)
        {
            printf("%d ", i);
            cnt++;
            total += i;
        }
        i++;
    } while (i <= (n < m ? m : n));
    printf("cnt=%d sum=%d\n", cnt, total);
    
    return 0;
}