#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, total = 0;
    int* saved = NULL;

    scanf("%d", &n);
    getchar();
    saved = (float *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", saved + i);
        total += *(saved + i);
    }
    printf("%d\n", total);
    free(saved);

    return 0;
}
