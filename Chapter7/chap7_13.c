#include <stdio.h>
#include <stdbool.h>
#define FIRST 3
#define SECOND 2

int main(void)
{
    int x[FIRST][FIRST];
    int y[SECOND][SECOND];
    bool flag = false;
    int i, j;
    int pos_x, pos_y;

    for (i = 0; i < FIRST; i++)
        for (j = 0; j < FIRST; j++)
            scanf("%d", &x[i][j]);
    for (i = 0; i < SECOND; i++)
        for (j = 0; j < SECOND; j++)
            scanf("%d", &y[i][j]);

    for (i = 0; i < FIRST; i++)
    {
        for (j = 0; j < FIRST; j++)
            printf(" %d", x[i][j]);
        putchar('\n');
    }
    for (i = 0; i < SECOND; i++)
    {
        for (j = 0; j < SECOND; j++)
            printf(" %d", y[i][j]);
        putchar('\n');
    }

    for (i = 0; i < SECOND; i++)
    {
        for (j = 0; j < SECOND; j++)
            if (x[i][j] == y[0][0] && x[i][j + 1] == y[0][1] && x[i + 1][j] == y[1][0] && x[i + 1][j + 1] == y[1][1] && !flag)
            {
                flag = true;
                pos_x = i;
                pos_y = j;
            }
    }
    if (flag == false)
        printf("none\n");
    else
        printf("%d %d\n", pos_x, pos_y);

    return 0;
}