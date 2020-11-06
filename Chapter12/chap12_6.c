#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char* name;
    int korean;
    int eng;
    int math;
    double avg;
} STU;

void input(STU*);
void result(STU*, int);
void memfree(STU*, int);

int main(void)
{
    int n, i;
    STU* info = NULL;

    scanf("%d", &n);
    info = (STU *)malloc(sizeof(STU) * n);
    for (i = 0; i < n; i++)
        input(info + i);
    result(info, n);
    memfree(info, n);
    return 0;
}

void input(STU* in)
{
    char temp[8];

    scanf("%s", temp);
    in->name = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
    strcpy(in->name, temp);

    scanf("%d %d %d", &in->korean, &in->eng, &in->math);
    getchar();
    in->avg = (double)(in->korean + in->eng + in->math) / 3;
}

void result(STU* struArr, int n)
{
    STU* pos = struArr;

    for (; pos < struArr + n; pos++)
    {
        printf("%s %.1lf ", pos->name, pos->avg);
        if(pos->korean >= 90 || pos->eng >= 90 || pos->math >= 90)
            printf("GREAT ");
        if (pos->korean < 70 || pos->eng < 70 || pos->math < 70)
            printf("BAD ");
        putchar('\n');
    }
}

void memfree(STU* struArr, int n)
{
    for (int i = 0; i < n; i++)
        free((struArr + i)->name);
    free(struArr);
}
