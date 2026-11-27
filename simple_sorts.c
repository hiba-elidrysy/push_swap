#include "push_swap.h"

//insertion sort list
// version 1
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

// version 2
// int    insertion_sort(t_list **heada, t_list **headb)
// {
//     int size;
//     int count;
//     int ops;

//     ops = 0;
//     if (*heada)
//         ops += ft_push(headb, heada, 'b');
//     while (*heada)
//     {
//         size = list_size(*headb);
//         count = 0;
//         while (size > 0 && (*heada)->data < (*headb)->data)
//         {
//             ops += ft_rotate(headb, 'b');
//             count++;
//             size--;
//         }
//         ops += ft_push(headb, heada, 'b');
//         size = list_size(*headb);
//         if (count <= size / 2)
//         {
//             while (count > 0)
//             {
//                 ops += ft_reverse_rotate(headb, 'b');
//                 count--;
//             }
//         }
//         else
//         {
//             count = size - count;
//             while (count > 0)
//             {
//                 ops += ft_rotate(headb, 'b');
//                 count--;
//             }
//         }
//     }
//     while (*headb)
//         ops += ft_push(heada, headb, 'a');
//     return (ops);
// }

//version 3
// int    insertion_sort(t_list **heada, t_list **headb)
// {
//     int     size;
//     int     pos;
//     int     max_pos;
//     int     i;
//     int     max;
//     int     ops;
//     t_list  *tmp;
//     t_list  *next;

//     ops = 0;
//     if (*heada)
//         ops += ft_push(headb, heada, 'b');
//     while (*heada)
//     {
//         size = list_size(*headb);
//         pos = -1;
//         max_pos = 0;
//         max = (*headb)->data;
//         tmp = *headb;
//         i = 0;
//         while (i < size)
//         {
//             if (tmp->data > max)
//             {
//                 max = tmp->data;
//                 max_pos = i;
//             }
//             next = tmp->next;
//             if (!next)
//                 next = *headb;
//             if (tmp->data > (*heada)->data
//                 && (*heada)->data > next->data)
//             {
//                 pos = (i + 1) % size;
//                 break ;
//             }
//             tmp = tmp->next;
//             i++;
//         }
//         if (pos == -1)
//             pos = max_pos;
//         if (pos <= size / 2)
//         {
//             while (pos-- > 0)
//                 ops += ft_rotate(headb, 'b');
//         }
//         else
//         {
//             i = size - pos;
//             while (i-- > 0)
//                 ops += ft_reverse_rotate(headb, 'b');
//         }
//         ops += ft_push(headb, heada, 'b');
//     }
//     size = list_size(*headb);
//     max = (*headb)->data;
//     max_pos = 0;
//     tmp = *headb;
//     i = 0;
//     while (tmp)
//     {
//         if (tmp->data > max)
//         {
//             max = tmp->data;
//             max_pos = i;
//         }
//         tmp = tmp->next;
//         i++;
//     }
//     if (max_pos <= size / 2)
//     {
//         while (max_pos-- > 0)
//             ops += ft_rotate(headb, 'b');
//     }
//     else
//     {
//         i = size - max_pos;
//         while (i-- > 0)
//             ops += ft_reverse_rotate(headb, 'b');
//     }
//     while (*headb)
//         ops += ft_push(heada, headb, 'a');
//     return (ops);
// }


// version 4

// int find_max(t_list *head)
// {
//     int tmp;
//     int pos;
//     int size;

//     pos = 0;
//     tmp = head->data;
//     size = list_size(head);
//     while(head)
//     {
//         if (tmp > head->data)
//         {
//             tmp = head->data;
//             pos++;
//         }
//         head = head->next;
//     }
//     return (pos);
// }


// int    insertion_sort(t_list **heada, t_list **headb)
// {
//     int size;
//     int count;
//     int ops;
//     int pos;

//     ops = 0;
//     pos = 0;
//     if (*heada)
//         ops += ft_push(headb, heada, 'b');
//     while (*heada)
//     {
//         size = list_size(*headb);
//         count = 0;
//         while (size > 0 && (*heada)->data < (*headb)->data)
//         {
//             ops += ft_rotate(headb, 'b');
//             count++;
//             size--;
//         }
//         ops += ft_push(headb, heada, 'b');
//     }
//     show_list(*headb);

//     pos = find_max(*headb);
//     size = list_size(*headb);
//     if (pos <= size / 2)
//     {
//         while(pos > 0)
//         {
//             ops += ft_reverse_rotate(headb, 'b');
//             pos--;
//         }
//     }
//     else
//     {
//         pos = size - pos;
//         while (pos > 0)
//         {
//             ops += ft_rotate(headb, 'b');
//             pos--;
//         }
//     }
    
//     while (*headb)
//         ops += ft_push(heada, headb, 'a');
//     return (ops);
// }


// version 5

// int    insertion_sort(t_list **heada, t_list **headb)
// {
//     int size;
//     int ops;
    
//     ops = 0;
//     if(*heada)
//         ops += ft_push(headb, heada, 'b');
//     while(*heada)
//     {
//         size = list_size(*headb);
//         while(size > 0)
//         {
//             if((*heada)->data > (*headb)->data)
//             {
//                 ops += ft_rotate(headb, 'b');
//             }
//             else
//             {
//                 ops += ft_push(headb, heada, 'b');
//             }
//             size--;
//         }
//     }
//     show_list(*headb);
//     while(*headb)
//         ops += ft_push(heada, headb, 'a');
//     return (ops);
// }


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

// bubble sort
int bubble_sort(t_list **heada, t_list **headb)
{
    int ops;
    int size;

    ops = 0;

    while(*heada)
    {
        size = list_size(*heada);
        while(size > 1)
        {
            if((*heada)->next->data < (*heada)->data)
            {
                ops += ft_swap(heada, 'a');
                ops += ft_rotate(heada, 'a');
            }
            else
                ops += ft_rotate(heada, 'a');
            size--;
        }
        ops += ft_push(headb, heada, 'b');
    }
    while(*headb)
    {
        ops += ft_reverse_rotate(headb, 'b');
        ops += ft_push(heada, headb, 'a');
    }
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

