#include <stdio.h>

int main(void)
{
    int n, total = 0, cnt = 0;
    double mean = .0;

    scanf("%d", &n);
    while (n > 0)
    {
        if (n > 100)
        {
            scanf("%d", &n);
            continue;
        }
        else if (n > 0 && n <= 100)
        {
            total += n;
            cnt++;
        }
        else if (n <= 0)
            break;
        scanf("%d", &n);
    }
    mean = (double)total / cnt;
    printf("%d %.2lf %d", total, mean, cnt);
    return 0;
}