#include <stdio.h>
#define STUDENT 3
#define SUBJECT 2

int main(void)
{
    int x[STUDENT][SUBJECT];
    int total[STUDENT] = { 0, };
    int i;

    for (i = 0; i < STUDENT; i++)
        for (int j = 0; j < SUBJECT; j++)
        {
            scanf("%d", &x[i][j]);
            total[i] += x[i][j];
        }
    for (i = 0; i < STUDENT; i++)
        printf("%d\n", total[i]);

    return 0;

}