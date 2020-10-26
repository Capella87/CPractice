#include <stdio.h>
#include <string.h>
#define MAX 20

int main(void)
{
    char a[MAX + 1], result[MAX * 10 + 1];
    char* pos = a, *pos2 = result;
    int temp = 0, i, n;

    scanf("%[^\n]", a);
    getchar();
    scanf("%d", &n);

    for (; pos <= a + strlen(a); pos++)
    {
        while (*pos >= '0' && *pos <= '9')
        {
            temp = temp * 10 + (int)(*pos - '0');
            pos++;
        }
        if (temp != 0)
        {
            for (i = 0; i < n; i++)
                *pos2++ = (char)temp + 'A' - 1;
            temp = 0;
        }

        if (*pos >= 'A' && *pos <= 'Z')
            *pos2++ = *pos + n;
        else if (*pos >= 'a' && *pos <= 'z')
            *pos2++ = *pos - n;
        else if ((*pos < '0' || *pos > '9') && *pos != '\0')
            *pos2++ = ' ';
    }
    *pos2 = '\0';
    puts(result);
 
    return 0;
}
