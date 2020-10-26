#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, d;
    int* id = NULL, *pos = NULL;
    
    scanf("%d", &n);
    getchar();
    id = (int *)malloc(sizeof(int) * n);

    for (pos = id; pos < id + n; pos++)
    {
        scanf("%d", pos);
        getchar();
    }
    scanf("%d", &d);
    id = (int *)realloc(id, sizeof(int) * (n - d));
    for (pos = id; pos < id + n - d; pos++)
        printf("%d\n", *pos);
    free(id);
    return 0;
}

