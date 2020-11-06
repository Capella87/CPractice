#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* chkMin(char**, int);
void typeIn(char**, int);
int freeElmt(char**, int);

int main(void)
{
    int n;
    char** saved = NULL;

    scanf("%d", &n);
    getchar();
    saved = (char**)malloc(sizeof(char*) * n);
    typeIn(saved, n);
    puts(chkMin(saved, n));
    freeElmt(saved, n);

    return 0;
}

void typeIn(char** input, int n)
{
    char** pos = input;
    char temp[101];
    for (; pos < input + n; pos++)
    {
        scanf("%[^\n]", temp);
        getchar();
        *pos = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
        strcpy(*pos, temp);
    }
}

char* chkMin(char** input, int n)
{
    char* min = *input;
    int i;

    for (i = 0; i < n; i++)
        if (strlen(*(input + i)) < strlen(min))
            min = *(input + i);
    return min;
}

int freeElmt(char** target, int size)
{
    for (int i = 0; i < size; i++)
        free(*(target + i));
    free(target);

    return 0;
}