#include <stdio.h>
#define PPL 5

struct student
{
    char name[10];
    int score;
};

int main(void)
{
    struct student members[PPL];
    double average;
    
    for (int i = 0; i < PPL; i++)
    {
        scanf("%9s %d", members[i].name, &members[i].score);
        getchar();
        average += (double)members[i].score;
    }
    average /= PPL;
    for (int i = 0; i < PPL; i++)
        if ((double)members[i].score <= average)
            puts(members[i].name);

    return 0;
}
