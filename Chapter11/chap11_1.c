#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct vtr
{
    int x;
    int y;
    int z;
};

int main(void)
{
    struct vtr v1;
    struct vtr v2;
    struct vtr v3;

    scanf("%d %d %d", &v1.x, &v1.y, &v1.z);
    getchar();
    scanf("%d %d %d", &v2.x, &v2.y, &v2.z);
    v3.x = v1.x * v2.x;
    v3.y = v1.y * v2.y;
    v3.z = v1.z * v2.z;
    printf("%d %d %d\n", v3.x, v3.y, v3.z);
    printf("%d\n", v3.x + v3.y + v3.z);

    return 0;
}
