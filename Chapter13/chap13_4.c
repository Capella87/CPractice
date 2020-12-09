#include <stdio.h>

int main(void)
{
    int input[4];
    unsigned int result = 0;

    for (int i = 0; i < 4; i++)
    {
        result <<= 8;
        scanf("%d", input + i);
        result += (unsigned int)input[i];
    }
    printf("%u\n", result);

    return 0;
}
