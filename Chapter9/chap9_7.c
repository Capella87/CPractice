#include <stdio.h>

void input(int*, int*, int*);
void output(int*, int*, int*);

int main(void)
{
    int a, b, c;
    input(&a, &b, &c);
    output(&a, &b, &c);
    return 0;
}

void input(int* first, int* second, int* third)
{
    scanf("%d %d %d", first, second, third);
}
void output(int* first, int* second, int* third)
{
    printf("%d %d %d\n", *first, *second, *third);
}