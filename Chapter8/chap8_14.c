#include <stdio.h>

int is_prime(int);
int next_prime(int);

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);
    fo
}

int is_prime(int x)
{
    for (int i = 1; i <= x; i++)
    {
        if (i > 1 && i < x && x % i == 0)
        {
            break;
            return 0;
        }
    }
    return 1;
}

int next_prime(int x)
{
    int i = x + 1;
    while (is_prime(i) == 0)
        i++;
    return i;
}