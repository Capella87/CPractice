#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct time
{
    int hr;
    int min;
    int sec;
    int totsec;
};

int main(void)
{
    struct time t1;
    struct time t2;
    int sec;

    scanf("%d %d %d", &t1.hr, &t1.min, &t1.sec);
    getchar();
    scanf("%d %d %d", &t2.hr, &t2.min, &t2.sec);
    t1.totsec = t1.hr * 3600 + t1.min * 60 + t1.sec;
    t2.totsec = t2.hr * 3600 + t2.min * 60 + t2.sec;
    sec = t2.totsec - t1.totsec;

    printf("%d %d %d\n", sec / 3600, sec % 3600 / 60, sec % 3600 % 60);

    return 0;
}
