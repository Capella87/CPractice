#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

struct info
{
    char name[MAX];
    int first;
    int second;
    int third;
    double avg;
    char credit;
};

void creditCalc(struct info*);

int main(void)
{
    int N, i;
    struct info students[MAX];
    struct info* pos = students;

    scanf("%d", &N);
    getchar();
    for (; pos < students + N; pos++)
    {
        scanf("%19s %d %d %d", pos->name, &pos->first, &pos->second, &pos->third);
        getchar();
        pos->avg = (double)(pos->first + pos->second + pos->third) / 3;
        creditCalc(pos);
        printf("%s %.1lf %c\n", pos->name, pos->avg, pos->credit);
    }

    return 0;
}

void creditCalc(struct info* a)
{
    if (a->avg >= 90)
        a->credit = 'A';
    else if (a->avg >= 80 && a->avg < 90)
        a->credit = 'B';
    else if (a->avg >= 70 && a->avg < 80)
        a->credit = 'C';
    else
        a->credit = 'F';
}
