#include "push_swap.h"

int main()
{
    int tab[] = {-1, -8, 5, 6, 1};
    int i;
    int j;
    int nbr;
    int size;
    int k;

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
            
            
            
            
            k = 0;
            while(k < (sizeof(tab) / sizeof(int)))
            {
                printf("%d ", tab[k]);
                k++;
            }
            printf("\n");





            j++;
        }
        printf("----\n");
        i++;
    }

    // // affichage
    // k = 0;
    // while(k < (sizeof(tab) / sizeof(int)))
    // {
    //     printf("%d\n", tab[k]);
    //     k++;
    // }

    return (0);
}




