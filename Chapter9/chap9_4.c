#include <stdio.h>
#define SIZE 3

int main(void)
{
    int x[SIZE];
    int* p;
    int* j;
    int temp;

    for (p = x; p < x + SIZE; p++)
        scanf("%d", p);
    for (p = x; p < x + SIZE - 1; p++)
    {
        for(j = x; j < x + SIZE - 1; j++)
        {
            if (*j > *(j + 1))
            {
                temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
    }
    printf("%d\n", *(x + 1));
    return 0;
}