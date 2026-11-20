#include "push_swap.h"

void min_max(int *tab, int start, int end, int *min, int *max)
{
    *min = start;
    *max = start;
    while(start < end)
    {
        if (tab[*min] > tab[start])
            *min = start;
        if (tab[*max] < tab[start])
            *max = start;
        start++;
    }
    // printf("min %d max %d\n", tab[*min], tab[*max]);
}
void    min_max_sort(int *tab, int size)
{
    int i;
    int tmp;
    int min;
    int max;

    i = 0;
    while(i < (size / 2))
    {
        min_max(tab, i, size, &min, &max);
        tmp = tab[i];
        tab[i] = tab[min];
        tab[min] = tmp;

        if (max == i)
            max = min;
        
        tmp = tab[size - 1];
        tab[size - 1] = tab[max];
        tab[max] = tmp;
        i++;
        size--;
    }
}

int main()
{
    int tab[] = {12, 9, 1, 0, 3 , 7, 0, -8, 50};
    int size;

    size = sizeof(tab) / sizeof(int);
    int i;
    min_max_sort(tab, size);
    i = 0;
    while(i < (sizeof(tab) / sizeof(int)))
    {
        printf("%d\n", tab[i]);
        i++;
    }
    return (0);
}