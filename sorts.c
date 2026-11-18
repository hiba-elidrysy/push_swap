#include "push_swap.h"

int main()
{
    int tab[] = {12, 9, 1, 0, 3 , 7, 0, -8};
    int i;
    int j;
    int tmp;
    int nbr;

    // selection sort
    i = 0;
    while(i < (sizeof(tab) / sizeof(int)))
    {
        j = i + 1;
        tmp = i;
        while(j < (sizeof(tab) / sizeof(int)))
        {
            if (tab[j] < tab[tmp])
                tmp = j;
            j++;
        }
        nbr = tab[i];
        tab[i] = tab[tmp];
        tab[tmp] = nbr;
        i++;
    }
    i = 0;
    while(i < (sizeof(tab) / sizeof(int)))
    {
        printf("%d\n", tab[i]);
        i++;
    }


    return (0);
}