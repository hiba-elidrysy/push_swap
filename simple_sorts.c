#include "push_swap.h"

//insertion sort
void insertion_sort(int *tab, int size)
{
    int i;
    int j;
    int tmp;

    i = 1;
    while(i < size)
    {
        tmp = tab[i];
        j = i - 1;
        while(j >= 0 && tmp < tab[j])
        {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = tmp;
        i++;
    }
}



//insertion sort list
void insertion_sort(t_list **head)
{
    t_list  *i;
    t_list  *j;
    int tmp;

    i = (*head)->next;
    prev = *head;
    while(i)
    {
        tmp = i->data;
        j = i;
        while()
    }
}

int main()
{
    int tab[] = {5, -1, 0, 2, 10, -8, 4};
    
    insertion_sort(tab, 7);
    int i;

    i = 0;

    while (i < 7)
    {
        printf("num : %d\n", tab[i]);
        i++;
    }
    return (0);
}