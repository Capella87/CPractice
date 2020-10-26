#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    float* saved = NULL, *max = NULL;

    scanf("%d", &n);
    getchar();
    saved = (float *)malloc(sizeof(float) * n);
    max = saved;
    for (i = 0; i < n; i++)
    {
        scanf("%f", saved + i);
        if (*max < *(saved + i))
            max = saved + i;
    }
    printf("%.2f\n", *max);
   
    free(saved); 
    return 0;
}
