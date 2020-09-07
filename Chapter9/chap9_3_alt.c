#include <stdio.h>

int main(void)
{
    int n, count = 0;
    int* p;
    scanf("%d", &n);
    int arr[n];
    
    for (p = arr; p < arr + n; p++)
        scanf("%d", p);
    p = arr;
    while (*p != 0)
    {
        p++;
        count++;
    }
    printf("%d\n", count);

    return 0;
}
