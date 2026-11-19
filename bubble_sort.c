#include "push_swap.h"

int main()
{
    int tab[] = {12, 9, 1, 0, 3 , 7, 0, -8};
    int i;
    int j;
    int nbr;
    int size;

    // bubble sort
    i = 0;
    size = (sizeof(tab) / sizeof(int));
    while (i < size)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (tab[j] > tab[j + 1])
            {
                nbr = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = nbr;
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