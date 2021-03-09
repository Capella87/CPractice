#include <stdio.h>
#include <stdbool.h>
#define SIZE 100

int* MAX(int*);
int* MIN(int*);

int main(void)
{
    int N;
    int ar[SIZE];
    int* a1, *a2;
    int* pos = ar;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++)
    {
        for (pos = ar; pos < ar + SIZE; pos++)
        {
            scanf("%d", pos);
            if (*pos == 0)
                break;
        }
        a1 = MAX(ar);
        a2 = MIN(ar);
        if (a1 - a2 >= -1 && a1 - a2 <= 1)
            printf("none");
        else
            for (pos = (a1 - a2 < 0 ? a1 + 1 : a2 + 1); pos < (a1 - a2 < 0 ? a2 : a1); pos++)
                printf("%d ", *pos);
        putchar('\n');
    }
    return 0;
}

int* MAX(int* input)
{
    int* pos = input;
    int* top = input;
    
    while (*pos != 0)
    {
        if (*top < *pos)
            top = pos;
        pos++;
    }
    return top;
}

int* MIN(int* input)
{
    int* pos = input;
    int* bottom = input;

    while (*pos != 0)
    {
        if (*bottom > *pos)
            bottom = pos;
        pos++;
    }
    return bottom;
}

