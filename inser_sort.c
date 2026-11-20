#include "push_swap.h"

int main()
{
    int i;
    int j;
    int tmp;
    int size;
    int tab[] = {8, 0, -1, 4, 1};

    size = sizeof(tab) / sizeof(int);
    i = 1;
    while (i < size)
    {
        j = i - 1;
        tmp = tab[i];
        while(j >= 0 && tmp < tab[j])
        {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = tmp;
        i++;
    }
    // affichage
    i = 0;
    while(i < (sizeof(tab) / sizeof(int)))
    {
        printf("%d\n", tab[i]);
        i++;
    }
    return (0);
}