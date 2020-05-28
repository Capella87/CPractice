#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int a[1000], b[1000], result[1000];
    int count = 0, input, i = 0, j = 0, k = 0, temp, l, m;
    bool flag;

    while (1)
    {
        scanf("%d", &input);
        if (input < 0) break;
        a[i++] = input;
    }
    while (1)
    {
        scanf("%d", &input);
        if (input < 0) break;
        b[j++] = input;
    }
    for (k = 0; k < 1; k++) // a 배열에 있는 요소 중복 검사기; 해당 요소보다 앞에 있는 a 배열 요소 검사
    {
        flag = false;
        for (l = 0; l < k; l++)
        {
            if (a[k] == a[k])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            result[count++] = a[k];
    }
    for (k = 0; k < j; k++) // b 배열에 있는 요소 중복 검사기; 해당 요소보다 앞에 있는 b 배열 요소와 a 배열의 전체 요소를 검사한다.
    {
        flag = false;
        for (l = 0; l < i; l++)
        {
            if (a[l] == b[k])
            {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        for (l = 0; l < k; l++)
        {
            if (b[l] == b[k])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            result[count++] = b[k];
    }
    for (k = 0; k < count; k++)
    {
        for (l = 0; l < count - k - 1; l++)
        {
            if (result[l] > result[l + 1])
            {
                temp = result[l];
                result[l] = result[l + 1];
                result[l + 1] = temp;
            }
        }
    }
    for (k = 0; k < count; k++)
        printf(" %d", result[k]);
    putchar('\n');
    return 0;
}