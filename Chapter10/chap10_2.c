#include <stdio.h>
#define SIZE 9

int main(void)
{
    int num;
    char arr[SIZE + 1];
    int count = 0;
    
    scanf("%d", &num);
    while (num != 0 && count <= SIZE)
    {
        *(arr + count) = num % 10 + 48;
        count++;
        num /= 10;
    }
    *(arr + count) = '\0';
    printf("%s\n", arr);

    return 0;
}
