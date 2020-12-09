#include <stdio.h>

void pswap(int**, int**);

int main(void)
{
    int x, y;
    int* px = &x, * py = &y;
    
    scanf("%d %d", &x, &y);
    pswap(&px, &py);
    printf("%d %d\n", *px, *py);

    return 0;
}

void pswap(int** ppx, int** ppy)
{
    int* temp = NULL;

    temp = *ppx;
    *ppx = *ppy;
    *ppy = temp;
}