#include <stdio.h>
#include <string.h>

struct result
{
    int best;
    int worst;
    char pass;
    int stdDiff;
    int diff;
};

void passorfail(struct result*);

int main(void)
{
    struct result student;
    
    scanf("%d %d %d", &student.best, &student.worst, &student.stdDiff);
    passorfail(&student);
    printf("%d %c\n", student.diff, student.pass);

    return 0;
}

void passorfail(struct result* input)
{
    input->diff = input->best - input->worst;
    if (input->diff <= input->stdDiff)
        input->pass = 'P';
    else
        input->pass = 'F';
}
