#include <stdio.h>
#include <string.h>

struct date
{
    char input[11];
    int year;
    int month;
    int day;
};

struct date* select_min(struct date*, struct date*);
void extractor(struct date*);

int main(void)
{
    struct date a, b;
    
    scanf("%[^\n]", a.input);
    getchar();
    scanf("%[^\n]", b.input);
    extractor(&a);
    extractor(&b);
    puts(select_min(&a, &b)->input);

    return 0;
}

struct date* select_min(struct date* a, struct date* b)
{
    if (a->year < b->year)
        return a;
    else if (a->year > b->year)
        return b;
    else if (a->year == b->year && a->month > b->month)
        return b;
    else if (a->year == b->year && a->month < b->month)
        return a;
    else if (a->year == b->year && a->month == b->month && a->day > b->day)
        return b;
    else if (a->year == b->year && a->month == b->month && a->day < b->day)
        return a;
    else
        return a;
}

void extractor(struct date* in)
{
    int temp = 0;
    int count = 0;
    for (int i = 0; i < 11; i++)
    {
        while (in->input[i] >= '0' && in->input[i] <= '9')
            temp = temp * 10 + (int)(in->input[i++] - '0');

        if (count == 0)
            in->year = temp;
        else if (count == 1)
            in->month = temp;
        else if (count == 2)
        {
            in->day = temp;
            break;
        }
        temp = 0;
        count++;   
    }
}
