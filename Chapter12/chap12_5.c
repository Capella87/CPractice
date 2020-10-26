#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, kch1count = 0, kch2count = 0;
    char* saved = NULL;
    char kch1, kch2;

    scanf("%d", &n);
    getchar();
    saved = (char *)malloc((n + 1) * sizeof(char));
    scanf("%[^\n]", saved);
    getchar();
    scanf("%c %c", &kch1, &kch2);
    getchar();
    for (char* pos = saved; pos < saved + n; pos++)
    {
        if (*pos == kch1)
            kch1count++;
        if (*pos == kch2)
            kch2count++;
    }
    printf("%d %d\n", kch1count, kch2count);
    free(saved);
    return 0;
}
