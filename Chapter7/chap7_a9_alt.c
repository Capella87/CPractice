#include <stdio.h>
#define SIZE 10

int main(void)
{
    int n, result = 0, i = 0;
    int x[SIZE]; // Use 10-size array that the problem required

    scanf("%d", &n);

    while (i != n)
    {
        scanf("%d", &x[i]);
        result = result * 10 + x[i++];
    }
    printf("%d\n", result);
    return 0;
}