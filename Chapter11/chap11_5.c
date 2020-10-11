#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
#define NAME 8

struct student 
{
    char name[NAME];
    int korean;
    int english;
    int math;
    double avg;
    char credit;
};

void creditCalc(struct student*);

int main(void)
{
    int N, i;
    struct student st[MAX];
    struct student* pos = st;

    scanf("%d", &N);
    getchar();
    for (; pos < st + N; pos++)
    {
        scanf("%7s %d %d %d", pos->name, &pos->korean, &pos->english, &pos->math);
        getchar();
        pos->avg = (double)(pos->korean + pos->english + pos->math) / 3;
        creditCalc(pos);
        printf("%s %.1lf %c\n", pos->name, pos->avg, pos->credit);
    }

    return 0;
}

void creditCalc(struct student* a)
{
    if (a->avg >= 90)
        a->credit = 'A';
    else if (a->avg >= 80 && a->avg < 90)
        a->credit = 'B';
    else if (a->avg >= 70 && a->avg < 80)
        a->credit = 'C';
    else
        a->credit = 'D';
}
