#include "push_swap.h"

//insertion sort list
int    insertion_sort(t_list **heada, t_list **headb)
{
    int size;
    int count;
    int ops;
    
    ops = 0;
    if(*heada)
        ops += ft_push(headb, heada, 'b');
    while(*heada)
    {
        size = list_size(*headb);
        count = 1;
        while(size >= 1 && (*heada)->data < (*headb)->data)
        {
            ops += ft_rotate(headb, 'b');
            count++;
            size--;
        }
        ops += ft_push(headb, heada, 'b');
        while(count > 1)
        {
            ops += ft_reverse_rotate(headb, 'b');
            count--;
        }
    }
    while(*headb)
        ops += ft_push(heada, headb, 'a');
    return (ops);
}



int selection_sort(t_list **heada, t_list **headb)
{
    int ops;
    int size;

    ops = 0;
    if (*heada)
        ops += ft_push(headb, heada, 'b');
    while(*heada)
    {
        size = list_size(*heada);
        while(size >= 1)
        {
            if((*heada)->data < (*headb)->data)
            {
                ops += ft_push(heada, headb, 'a');
                ops += ft_swap(heada, 'a');
                ops += ft_push(headb, heada, 'b');
                ops += ft_rotate(heada, 'a');
            }
            else
                ops += ft_rotate(heada, 'a');
            size--;
        }
        ops += ft_push(headb, heada, 'b');
    }
    while(*headb)
            ops += ft_push(heada, headb, 'a');
    return (ops);
}


//insertion sort
// void insertion_sort(int *tab, int size)
// {
//     int i;
//     int j;
//     int tmp;

//     i = 1;
//     while(i < size)
//     {
//         tmp = tab[i];
//         j = i - 1;
//         while(j >= 0 && tmp < tab[j])
//         {
//             tab[j + 1] = tab[j];
//             j--;
//         }
//         tab[j + 1] = tmp;
//         i++;
//     }
// }

