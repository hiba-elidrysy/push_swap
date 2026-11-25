/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-idry <hel-idry@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 15:44:45 by hel-idry          #+#    #+#             */
/*   Updated: 2026/11/25 20:57:53 by hel-idry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int    insert_sort(t_list **heada, t_list **headb)
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



int main(int argc, char **argv)
{
    char **str = NULL;
    int i;
    int count;
    char *total;
    int *num;
    t_list *heada;
    t_list *headb;
    int ops = 0;
    

    heada = NULL;
    headb = NULL;
    total = ft_strjoin((const char**)argv, argc);
    count = count_nbr(total);
    // printf("size : %d\n", count);
    if (total)
        str = ft_split(total);
    num = malloc(count * sizeof(int));
    i = 0;
    while(str[i])
    {
        num[i] = ft_atoi(str[i]);
        i++;
    }
    heada = new_list(num, count);
    // printf("here ---- %d", heada->data);
    // printf("%p\n", heada);
    printf("-----before insertion sort------\n");
    show_list(heada);
    
    printf("-----after insertion sort------\n");
    ops = insert_sort(&heada, &headb);
    show_list(heada);
    delete_list(heada);
    delete_list(headb);
    return (0);
}



// int main(int argc, char **argv)
// {
//     char **str = NULL;
//     int i;
//     int count;
//     char *total;
//     int *num;
    
//     total = ft_strjoin((const char**)argv, argc);
//     count = count_nbr(total);
//     if (total)
//         str = ft_split(total);
//     num = malloc(count * sizeof(int));
//     i = 0;
//     while(str[i])
//     {
//         num[i] = ft_atoi(str[i]);
//         i++;
//     }
//     i = 0;
//     while(i < count)
//         printf("num %d\n", num[i++]);
    
//     return (0);
// }






// int main(int argc, char **argv)
// {
//     char **str = NULL;
//     int i;
//     int count;
//     char *total;
    
//     total = ft_strjoin((const char**)argv, argc);
//     count = count_nbr(total);
//     // printf("main total : %s\n", total);
//     if (total)
//         str = ft_split(total);
//     // printf("test : %s\n", *(str + 1));
//     // (void)argc;
//     // (void)argv;
//     i = 0;
//     if (!str)
//         return (0);
//     while(str[i])
//     {
//         printf("%s\n", str[i]);
//         i++;
//     }
    
//     return (0);
// }







// int main()
// {
//     t_list  *heada;
//     t_list  *headb;
//     t_list  *n;
//     int num = 0;
//     int tab1[] = {2, 0, 5, -1};
//     // int tab1[] = {5, -1, 0, 2};
//     // int tab1[] = {-1, -8, 5, 6, 1};
//     // int tab1[] = {5, 4, 3, 2, 1 , 0};
//     // int tab1[] = {12, 9, 1, 0, 3 , -4, 100};
//     // int tab1[] = {5, 4, 3, 2, 1};
//     // int tab1[] = {1, 2, 3, 4, 5};


//     int size1 = sizeof(tab1) / sizeof(int);

//     heada = new_list(tab1, size1);
//     headb = NULL;
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top : ");
//     while(n)
//     {
//         printf("| %d | -> ", n->data);
//         n = n->next;
//     }
//     printf("NULL : bottom\n");
//     printf("list size a : %d\n", list_size(heada));

//     printf("----------insert sort---------\n");
//     num = insert_sort(&heada, &headb);
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top : ");
//     while(n)
//     {
//         printf("| %d | -> ", n->data);
//         n = n->next;
//     }
//     printf("NULL : bottom\n");
//     printf("list size a : %d\n", list_size(heada));

//     printf("ops number : %d\n", num);
//     delete_list(heada);
//     delete_list(headb);
//     return (0);
// }






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