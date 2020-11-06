#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void typeIn(int*, int);
void swap(int*, int);
void printOut(int*, int);

int main(void)
{
    int n;
    int* saved = NULL;

    scanf("%d", &n);
    getchar();
    saved = (int *)malloc(sizeof(int) * n);
    typeIn(saved, n);
    swap(saved, n);
    printOut(saved, n);
    free(saved);

    return 0;
}

void typeIn(int* input, int size)
{
    int* pos = input;
    for (; pos < input + size; pos++)
        scanf("%d", pos);
}

void swap(int* input, int size)
{
    int* pos = input;
    int temp;

    for (; pos < input + size - 1; pos++)
    {
        if(*pos > *(pos + 1))
        {
            temp = *pos;
            *pos = *(pos + 1);
            *(pos + 1) = temp;
        }
    }
}

void printOut(int* input, int size)
{
    int* pos = input;
    for (; pos < input + size; pos++)
        printf("%d\n", *pos);
}
