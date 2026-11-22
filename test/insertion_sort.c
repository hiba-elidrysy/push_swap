#include "push_swap.h"

int main()
{
    int tab[] = {12, 9, 1, 0, 3 , 7, 0, -8};
    int i;
    int j;
    int nbr;

    // insertion sort
    i = 1;
    while (i < (sizeof(tab) / sizeof(int)))
    {
        nbr = tab[i];
        j = i - 1;
        while(j >= 0 && tab[j] > nbr)
        {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = nbr;
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