#include <stdio.h>
#include <string.h>
#define SIZE 37

int main(void)
{
    char result[SIZE];
    char numboard[5];
    const char* numstr[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    const char* digitchar[3] = { "THO", "HUN", "TEN" };
    char* pos = numboard + 3;
    int num, count = 0;

    scanf("%d", &num);
    for (int digit = 0; digit < 4; digit++)
    {
        *(pos--) = num % 10 + 48;
        num /= 10;
    }
    *(numboard + 4) = '\0';
    pos = numboard;
    while (pos - numboard <= 3)
    {
        if (*pos == '0')
        {
            pos++;
            continue;
        }
        count += sprintf(result + count, "%s ", numstr[*pos - 48 - 1]);
        if (pos - numboard < 3)
            count += sprintf(result + count, "%s ", digitchar[pos - numboard]);
        pos++;
    }
    puts(result);
    return 0;
}