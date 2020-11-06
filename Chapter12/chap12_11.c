#include <stdio.h>
#include <stdlib.h>

void printOut(int**, int);
void freeElmt(int**, int);

int main(void)
{
    int** packet = (int **)malloc(sizeof(int *) * 6);
    int pcount = 0, i, curidx;

    *packet = (int *)malloc(sizeof(int) * 5);
    for (i = 0; i < 20; i++)
    {
        if (i == 5 || i == 8 || i == 11 || i == 14 || i == 17)
            *(packet + ++pcount) = (int* )malloc(sizeof(int) * 3);
        curidx = (i < 5) ? i : (i - 5) % 3;
        scanf("%d", &packet[pcount][curidx]);
        if (*(*(packet + pcount) + curidx) == -1)
        {
            i++;
            break;
        }
    }
    printOut(packet, i);
    freeElmt(packet, pcount);
    return 0;
}

void printOut(int** target, int count)
{
    int curidx, i, tcount = 0;

    for (i = 0; i < count; i++)
    {
        if (i == 5 || i == 8 || i == 11 || i == 14 || i == 17)
            tcount++;
        curidx = (i < 5) ? i : (i - 5) % 3;
        printf("%d ", *(*(target + tcount) + curidx));
    }
    putchar('\n');
}

void freeElmt(int** target, int tcount)
{
    int** pos = target;

    for (; pos < target + tcount; pos++)
        free(*pos);
    free(target);
}
