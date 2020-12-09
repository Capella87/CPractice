#include <stdio.h>

int add(int, int);

int main(void)
{
    int A, x, y;
    void* saved = NULL;
    int (*fp)(int, int);
    fp = add;

    scanf("%d", &A);
    getchar();
    saved = &A;
    scanf("%d %d", &x, &y);

    printf("%d\n", *(int*)saved);
    printf("%d\n", fp(x, y));

    return 0;
}

int add(int a, int b)
{
    return a + b;
}