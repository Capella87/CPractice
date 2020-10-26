#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char** pch = NULL;
    int row, col, i, j;
    char stat = 'a';

    scanf("%d %d", &row, &col);
    getchar();
    pch = (char **)malloc(row * sizeof(char* ));
    for (i = 0; i < row; i++)
    {
        pch[i] = (char* )malloc(col * sizeof(char));
        for (j = 0; j < col; j++)
        {
            *(*(pch + i) + j) = stat;
            if (stat == 'z')
                stat = 'A';
            else if (stat == 'Z')
                stat = 'a';
            else
                stat++;
        }
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%c ", *(*(pch + i) + j));
        putchar('\n');
        free(pch[i]);
    }

    return 0;
}
