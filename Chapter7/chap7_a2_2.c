#include <stdio.h>
#define STUDENTS 3
#define SUBJECTS 2

// 학생별 국어와 영어 성적 합을 출력한다.

int main(void)
{
    int saved[STUDENTS][SUBJECTS];
    int i, j, total;

    for (i = 0; i < STUDENTS; i++)
    {
        total = 0;
        for (j = 0; j < SUBJECTS; j++)
        {
            scanf("%d", &saved[i][j]);
            total += saved[i][j];
        }
        printf("%d\n", total);
    }
    return 0;
}