#include "push_swap.h"

int main()
{
    int tab[] = {12, 9, 1, 0, 3 , 7, 0, -8};
    int i;
    int j;
    int nbr;

    // insertion sort
    i = 0;
    j = i + 1;
    while(i < (sizeof(tab) / sizeof(int)))
    {
        j = i + 1;
        while(j < (sizeof(tab) / sizeof(int)))
        {
            if (tab[j] < tab[i])
            {
                nbr = tab[i];
                tab[i] = tab[j];
                tab[j] = nbr;
            }
            j++;
        }
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