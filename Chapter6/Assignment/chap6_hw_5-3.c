#include <stdio.h>

int main(void)
{
    int n, even_reversed = 0, odd_reversed = 0;
    scanf("%d", &n);

    while (n != 0)
    {
        if (n % 10 % 2 == 0)
            even_reversed = even_reversed * 10 + n % 10;
        else
            odd_reversed = odd_reversed * 10 + n % 10;
        n /= 10;
    }
    printf("%d %d\n", even_reversed, odd_reversed);
    return 0;
}