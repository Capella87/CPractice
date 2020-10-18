#include <stdio.h>
#include <string.h>
#define PPL 10

struct result
{
    char name[10];
    int q1;
    int q2;
    int q3;
    double average;
};

void read_data(struct result[]);
void cal_avg(struct result[]);
void sort(struct result[]);
void print_score(struct result[]);

int main(void)
{
    struct result students[PPL], temp;

    read_data(students);
    cal_avg(students);
    sort(students);
    print_score(students);
    return 0;
}

void read_data(struct result input[])
{
    for (int i = 0; i < PPL; i++)
    {
        scanf("%9s %d %d %d", input[i].name, &input[i].q1, &input[i].q2, &input[i].q3);
        getchar();
    }
}

void cal_avg(struct result input[])
{
    for (int i = 0; i < PPL; i++)
        input[i].average = (double)(input[i].q1 + input[i].q2 + input[i].q3) / 3;
}

void sort(struct result input[])
{
    struct result temp;
    
    for (int i = 0; i < PPL - 1; i++)
    {
        for (int j = 0; j < PPL - 1 - i; j++)
        {
            if (input[j].average < input[j + 1].average)
            {
                temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
}

void print_score(struct result input[])
{
    printf("%s %.2lf\n", input[0].name, input[0].average);
    printf("%s %.2lf\n", input[PPL - 1].name, input[PPL - 1].average);
    for (int i = 7; i < PPL; i++)
        printf("%s %.2lf\n", input[i].name, input[i].average);
}