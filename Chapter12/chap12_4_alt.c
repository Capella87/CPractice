#include <stdio.h>
#include <stdlib.h>

// Use Variable-Length Array

int main(void)
{
    int row, col, i, j;
    char stat = 'a';

    scanf("%d %d", &row, &col);
    getchar();
    char(* pch)[col] = (char (*)[col])malloc(row * col * sizeof(char));

    for (i = 0; i < row; i++)
    {
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
    }
    free(pch);

    return 0;
}

