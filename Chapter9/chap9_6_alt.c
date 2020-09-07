#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define SIZE 10

int main(void)
{
    char arr[SIZE];
    int stat[SIZE][2] = { 0, };
    char* pos;
    int(*pos2)[2] = stat;
    int(*max)[2] = stat;
    int spellcount = 0;
    bool same = false;

    for (pos = arr; pos < arr + SIZE; pos++)
    {
        same = false;
        scanf("%c", pos);
        *pos = tolower(*pos);
        for (pos2 = stat; pos2 < stat + spellcount; pos2++)
        {
            if (**pos2 == (int)*pos)
            {
                *(*pos2 + 1) += 1;
                same = true;
                break;
            }
            else continue;
        }
        if (!same)
        {
            **(stat + spellcount) = (int)*pos;
            *(*(stat + spellcount) + 1) += 1;
            spellcount++;
        }
        if (*(*pos2 + 1) > * (*max + 1))
            max = pos2;
        else if (*(*pos2 + 1) == *(*max + 1) && pos2 - max < 0)
            max = pos2;
    }
    printf("%c %d\n", (char)**max, *(*max + 1));
    
    return 0;
}