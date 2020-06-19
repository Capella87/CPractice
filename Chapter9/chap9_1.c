#include <stdio.h>

int main(void)
{
    int x, y, z;
    int *px, *py, *pz, *tmp;

    px = &x;
    py = &y;
    pz = &z;
    tmp = NULL;
    scanf("%d %d %d", px, py, pz);

    tmp = pz;
    pz = py;
    py = px;
    px = tmp;

    printf("%d %d %d\n", *px, *py, *pz);
    return 0;
}