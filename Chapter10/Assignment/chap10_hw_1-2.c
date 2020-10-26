#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20

int inspector(char*, char*);
char* converter(char*, size_t, int);

int main(void)
{
    char a[21];
    char b[21];
    
    scanf("%[^\n]", a);
    getchar();
    scanf("%[^\n]", b);
    
    printf("%d\n", inspector(a, b));
    
    return 0;
}

int inspector(char* a, char* b)
{
    int N;
    int ret = 0;
    bool fwflag = false, bwflag = false;
    
    for (N = 1; N <= 10; N++)
    {
        if (!fwflag && strcmp(converter(a, strlen(a), N), b) == 0)
        {
            ret++;
            fwflag = true;
        }
        if (!bwflag && strcmp(converter(b, strlen(b), N), a) == 0)
        {
            ret += 2;
            bwflag = false;
        }
        if (fwflag && bwflag)
            break;
    }
    
    return ret;
}

char* converter(char* input, size_t len, int N)
{
    char output[1001];
    char* pos = input, *pos2 = output;
    int temp = 0, i;
    
    for (; pos <= input + len; pos++)
    {
        while (*pos >= '0' && *pos <= '9')
        {
            temp = temp * 10 + (int)(*pos - '0');
            pos++;
        }
        if (temp != 0)
        {
            for (i = 0; i < N; i++)
                *pos2++ = (char)temp + 'A' - 1;
            temp = 0;
        }

        if (*pos >= 'A' && *pos <= 'Z')
            *pos2++ = *pos + N;
        else if (*pos >= 'a' && *pos <= 'z')
            *pos2++ = *pos - N;
        else if ((*pos < '0' || *pos > '9') && *pos != '\0')
            *pos2++ = ' ';
    }
    *pos2 = '\0';
    pos2 = output;
    
    return pos2;
}