#include <stdio.h>
#define MAX 10

struct student
{
    int gender;
    int weight;
    int height;
};

void result(struct student*, int);

int main(void)
{
    int n, i;
    struct student info[MAX];

    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &info[i].gender, &info[i].weight, &info[i].height);
        getchar();
    }
    result(info, n);

    return 0;
}

void result(struct student* pos, int count)
{
    int a = 0, b = 0, c = 0;

    for (int i = 0; i < count; i++, pos++)
    {
        switch(pos->gender)
        {
        case 1:
            if (pos->weight < 60 && pos->height < 165 || pos->weight >= 60 && pos->weight < 70 && pos->height >= 165 && pos->height < 175 || pos->weight >= 70 && pos->height >= 175)
                a++;
            else if (pos->weight< 60 && pos->height >= 165 && pos->height < 175 || pos->height >= 175 && pos->weight >= 60 && pos->weight < 70 || pos->weight >= 70 && pos->height < 165)
                b++;
            else
                c++;
            break;
        case 2:
            if (pos->weight < 50 && pos->height < 165 || pos->weight >= 50 && pos->weight < 60 && pos->height >= 165 && pos->height < 175 || pos->weight >= 60 && pos->height >= 175)
                a++;
            else if (pos->weight >= 60 && pos->height < 165 || pos->weight < 50 && pos->height >= 165 && pos->height < 175 || pos->weight >= 50 && pos->weight < 60 && pos->height >= 175)
                b++;
            else
                c++;
        }
    }
    printf("%d %d %d\n", a, b, c);
}
