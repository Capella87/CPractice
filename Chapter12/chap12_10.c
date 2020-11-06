#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char**, int);
void typeIn(char**, int);
int freeElmt(char**, int);
void printOut(char**, int);

int main(void)
{
    int n;
    char** saved = NULL;

    scanf("%d", &n);
    getchar();
    saved = (char**)malloc(sizeof(char*) * n);
    typeIn(saved, n);
    swap(saved, n);
    printOut(saved, n);
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

void swap(char** input, int n)
{
    char* temp;
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (strlen(*(input + j)) < strlen(*(input + j + 1)))
            {
                temp = *(input + j);
                *(input + j) = *(input + j + 1);
                *(input + j + 1) = temp;
            }
        }
    }
}

int freeElmt(char** target, int size)
{
    for (int i = 0; i < size; i++)
        free(*(target + i));
    free(target);

    return 0;
}

void printOut(char** input, int n)
{
    char** pos = input;
    for (; pos < input + n; pos++)
        puts(*pos);
}
