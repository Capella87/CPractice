#include <stdio.h>
#define MAX 20

void addArray(int*, int*, int*, int);

int main(void)
{
    int n;
    int first[MAX];
    int second[MAX];
    int result[MAX] = { 0, };
    int* pos = NULL;
    scanf("%d", &n);

    for (pos = first; pos < first + n; pos++)
        scanf("%d", pos);
    for (pos = second; pos < second + n; pos++)
        scanf("%d", pos);
    addArray(first, second, result, n);
    for (pos = result; pos < result + n; pos++)
        printf(" %d", *pos);
    putchar('\n');

    return 0;
}

void addArray(int* first, int* second, int* destination, int size)
{
    int* pos = first;
    int* pos2 = second + size - 1;
    int* pos3 = destination;

    for (; pos < first + size; pos++, pos2--)
    {
        *pos3 = *pos + *pos2;
        pos3++;
    }
}
