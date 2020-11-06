#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void typeIn(char**, int);
void sort(char**, int);
void printOut(char**, int);
void freeElmt(char**, int);

int main(void)
{
    int n;
    char** saved;

    scanf("%d", &n);
    getchar();
    saved = (char **)malloc(sizeof(char *) * n);
    typeIn(saved, n);
    sort(saved, n);
    putchar('\n');
    printOut(saved, n);
    freeElmt(saved, n);

    return 0;
}

void typeIn(char** input, int size)
{
    char** pos = input;
    char temp[101];

    for (; pos < input + size; pos++)
    {
        scanf("%[^\n]", temp);
        getchar();
        *pos = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
        strcpy(*pos, temp);
    }
}

void sort(char** target, int size)
{
    int i, j;
    char* temp = NULL;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (strcmp(*(target + j), *(target + j + 1)) > 0)
            {
                temp = *(target + j);
                *(target + j) = *(target + j + 1);
                *(target + j + 1) = temp;
            }
        }
    }
}

void printOut(char** target, int size)
{
    char** pos = target;
    for (; pos < target + size; pos++)
        puts(*pos);
}

void freeElmt(char** target, int size)
{
    char** pos = target;
    for (; pos < target + size; pos++)
        free(*pos);
    free(target);
}
