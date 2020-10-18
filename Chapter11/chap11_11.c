#include <stdio.h>
#include <string.h>
#define SIZE 10
#define PPL 5

struct result
{
    char name[SIZE];
    int score;
};

struct result* select_min(struct result*);

int main(void)
{
    struct result list[PPL], *min;

    for (int i = 0; i < PPL; i++)
    {
        scanf("%9s %d", list[i].name, &list[i].score);
        getchar();
    }
    min = select_min(list);
    printf("%s %d\n", min->name, min->score);

    return 0;
}

struct result* select_min(struct result* input)
{
    struct result* min = input, *pos = input;

    for (pos = input + 1; pos < input + PPL; pos++)
        if (min->score > pos->score)
            min = pos;

    return min;
}

