#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 3
#define STR "cat"

int finder(char*);

int main(void)
{
    int n;
    char* saved = NULL;

    scanf("%d", &n);
    getchar();
    saved = (char* )malloc(sizeof(char) * (n + 1));
    scanf("%[^\n]", saved);
    printf("%d\n", finder(saved));

    free(saved);
    return 0;
}

int finder(char* input)
{
    size_t len = strlen(input);
    char* pos = input;
    int count = 0;

    for (; pos < input + len - SIZE + 1; pos++)
    {
        if (strncmp(pos, STR, SIZE) == 0)
        {
            count++;
            pos += 2;
            continue;
        }
    }

    return count;
}
