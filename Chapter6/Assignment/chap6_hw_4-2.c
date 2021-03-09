#include <stdio.h>

int main(void)
{
    int t;
    int input, cnt1 = 0, cnt2 = 0, cnt3 = 0;

    scanf("%d", &t);
    scanf("%d", &input);

    while (input)
    {
        while (input /= 10)
        {
            if (input % 10 == t)
                cnt1++;
            else if (input % 10 < t)
                cnt2++;
            else if (input % 10 > t)
                cnt3++;
        }
        scanf("%d", &input);
    }
    printf("%d %d %d", cnt1, cnt2, cnt3);
    
    return 0;
}