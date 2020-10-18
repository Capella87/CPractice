#include <stdio.h>
#include <string.h>
#define SIZE 10

struct num
{
    int list[SIZE];
    int rank[SIZE];
};

struct num* sort(struct num*);
void printOut(struct num*);

int main(void)
{
    struct num data = { { 0, }, { 0, }};

    for (int i = 0; i < SIZE; i++)
        scanf("%d", &data.list[i]);
    sort(&data);
    printOut(&data);
    return 0;
}

struct num* sort(struct num* input)
{
    int count;

    for (int i = 0; i < SIZE; i++)
    {
        count = 0;
        for (int j = 0; j < SIZE; j++)
            if (input->list[i] < input->list[j])
                count++;
        input->rank[i] = count + 1;
    }
}

void printOut(struct num* input)
{
    int i, skip = -1;

    for (i = 0; i < SIZE; i++)
    {
        if (i == skip || (input->rank[i] == 7 && skip == -1))
            continue;
        else if (input->rank[i] == 7 && skip != -1)
        {
            printf("%d\n", input->list[i]);
            break;
        }
        else if (input->rank[i] == 3)
        {
            skip = i;
            printf("%d ", input->list[i]);
            i = 0;
        }
    }
}
