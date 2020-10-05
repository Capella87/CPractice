#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    char saved[100][101];
    char* min = NULL;
    size_t minlen;
    int N, i;

    scanf("%d", &N);
    getchar();
    for (i = 0; i < N; i++)
    {
        scanf("%[^\n]", saved[i]);
        getchar();
        if (i == 0)
        {
            min = saved[i];
            minlen = strlen(saved[i]);
            continue;
        }
        if (minlen > strlen(saved[i]))
        {
            min = saved[i];
            minlen = strlen(saved[i]);
        }
    }
    puts(min);
    return 0;
}