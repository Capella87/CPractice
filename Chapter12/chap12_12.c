#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int assignment(int*, int, bool);
void printOut(int*, int);

int main(void)
{
    int n;
    int* orig = NULL;
    int* out = NULL;

    scanf("%d", &n);
    orig = (int *)malloc(sizeof(int) * n);
    out = (int *)malloc(sizeof(int) * (n - 1));
    assignment(orig, n, true);
    assignment(out, n - 1, false);
    printOut(out, n - 1);

    free(orig);
    free(out);

    return 0;
}

int assignment(int* input, int n, bool cent)
{
    int num;
    switch((int)cent)
    {
        case 1:
            for (num = 0; num < n; num++)
                *(input + num) = num;
            break;
        case 0:
            num = 0;
            for (int i = 0, num = 0; i < n; i++, num++)
            {
                if (num == n / 2)
                    num++;
                *(input + i) = num;
            }
            break;
    }
    return 0;
}

void printOut(int* target, int size)
{
    int* pos = target;
    for (; pos < target + size; pos++)
        printf(" %d", *pos);
    putchar('\n');
}
