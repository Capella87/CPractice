#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

int main(void)
{
    char ch[SIZE];
    int count[SIZE] = { 0, };
    char* ptr, *ptr2, *max = ch;
    int* status, *cnt_max = count;
    int i, cnt = 0;
    bool flag;

    for (ptr = ch; ptr < ch + SIZE; ptr++)
        scanf("%c", ptr);
    for (ptr = ch; ptr < ch + SIZE ; ptr++)
    {
        flag = false;
        for (ptr2 = ch; ptr2 < ptr; ptr2++)
        {
            if (*ptr2 == *ptr)
            {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        for (ptr2 = ptr; ptr2 < ch + SIZE; ptr2++)
        {
            if (*ptr2 == *ptr)
                *(count + cnt) = *(count + cnt) + 1;
        }
        if (*cnt_max < *(count + cnt))
        {
            max = ptr;
            cnt_max = count + cnt;
        }
        cnt++;
    }
    printf("%c %d\n", *max, *cnt_max);
    return 0;
}