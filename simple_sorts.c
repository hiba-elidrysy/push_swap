#include "push_swap.h"

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



//insertion sort list
void    insert_sort(t_list **heada, t_list **headb)
{
    t_list  *tmp;
    int     k;
    int     i;

    while (*heada)
    {
        k = 0;
        tmp = *headb;
        while (tmp && tmp->data > (*heada)->data)
        {
            k++;
            tmp = tmp->next;
        }
        i = 0;
        while (i++ < k)
            ft_rotate(headb);
        ft_push(headb, heada);
        i = 0;
        while (i++ < k)
            ft_reverse_rotate(headb);
    }
    while (*headb)
        ft_push(heada, headb);
}


int main()
{
    t_list  *heada;
    t_list  *headb;
    t_list  *n;
    // int tab1[] = {2, 0, 5, -1};
    int tab1[] = {5, -1, 0, 2};
    int size1 = sizeof(tab1) / sizeof(int);

    heada = new_list(tab1, size1);
    headb = NULL;
    n = heada;
    printf("----------stack a---------\n");
    printf("top : ");
    while(n)
    {
        printf("| %d | -> ", n->data);
        n = n->next;
    }
    printf("NULL : bottom\n");
    printf("list size a : %d\n", list_size(heada));

    printf("----------insert sort---------\n");
    insert_sort(&heada, &headb);
    n = heada;
    printf("----------stack a---------\n");
    printf("top : ");
    while(n)
    {
        printf("| %d | -> ", n->data);
        n = n->next;
    }
    printf("NULL : bottom\n");
    printf("list size a : %d\n", list_size(heada));

    delete_list(heada);
    delete_list(headb);
    return (0);
}






// int main()
// {
//     int tab[] = {5, -1, 0, 2, 10, -8, 4};
    
//     insertion_sort(tab, 7);
//     int i;

//     i = 0;

//     while (i < 7)
//     {
//         printf("num : %d\n", tab[i]);
//         i++;
//     }
//     return (0);
// }