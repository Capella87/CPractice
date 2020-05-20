#include <stdio.h>

int main(void)
{
    int answer, input, count = 0;

    scanf("%d", &answer);
    do
    {
        scanf("%d", &input);
        if (input > answer) printf("%d>?\n", input);
        else if (input < answer) printf("%d<?\n", input);
        count++;
    } while (input != answer);
    printf("%d==?\n", answer);
    printf("%d\n", count);
    return 0;
}