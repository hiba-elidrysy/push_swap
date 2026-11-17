/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-idry <hel-idry@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 21:42:43 by hel-idry          #+#    #+#             */
/*   Updated: 2026/11/17 18:41:34 by hel-idry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list t_list;

typedef struct s_list
{
    int data;
    t_list  *next;
}   t_list;

typedef enum s_mode
{
    SA,
    SB,
    SS,
    PA,
    PB,
    RA,
    RB,
    RR,
    RRA,
    RRB,
    RRR
}   t_mode;

char    **ft_split(const char *str)
{
    
}

int ft_atoi(const char *str)
{
    long nbr;
    int sign;

    nbr = 0;
    sign = 1;
    while (*str == ' ')
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while(*str >= '0' && *str <= '9')
    {
        nbr = nbr * 10 + (*str - '0');
        str++;
    }
    return ((int)(nbr * sign));
}

t_list  *new_node(int data)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->data = data;
    new->next = NULL;
    return (new);
}

void    add_node_back(t_list *head, t_list *node)
{    
    while(head->next)
        head = head->next;
    head->next = node;
}

void    free_list(t_list *head)
{
    t_list  *tmp;

    while(head)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

int list_size(t_list *head)
{
    int count;

    count = 0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return (count);
}

void    ft_swap(t_list **head, int size)
{
    t_list  *prev;
    t_list  *last;
    t_list  *before_last;

    if (size <= 1)
        return ;
    if (size == 2)
    {
        last = (*head)->next;
        last->next = *head;
        (*head)->next = NULL;
        *head = last;
        return ;
    }
    prev = *head;
    while (prev->next->next->next)
        prev = prev->next;
    before_last = prev->next;
    last = before_last->next;
    prev->next = last;
    last->next = before_last;
    before_last->next = NULL;
}
void    ft_push(t_list **head1, t_list **head2)
{
    t_list  *node1;
    t_list  *node2;

    if (!*head2)
        return ;
    node2 = *head2;
    if (node2->next)
    {
        while (node2->next->next)
            node2 = node2->next;
        node1 = node2->next;
        node2->next = NULL;
    }
    else
    {
        node1 = *head2;
        *head2 = NULL;
    }
    if (!*head1)
        *head1 = node1;
    else
    {
        node2 = *head1;
        while (node2->next)
            node2 = node2->next;
        node2->next = node1;
    }
}

void    ft_rotate(t_list **head)
{
    t_list  *last;
    t_list  *next;

    if (!*head || !(*head)->next)
        return ;
    last = *head;
    while(last->next)
        last = last->next;
    next = (*head)->next;
    (*head)->next = NULL;
    last->next = (*head);
    (*head) = next;
}

void    ft_rotate_reverse(t_list **head)
{
    t_list  *last;
    t_list  *prev;
    
    if (!*head || !(*head)->next)
        return ;
    last = *head;
    while(last->next->next)
        last = last->next;
    prev = last;
    last = last->next;
    prev->next = NULL;
    
    last->next = (*head);
    (*head) = last;
}

float   compute_disorder(t_list **head)
{
    float   mistakes;
    float   total_pairs;
    int size;
    int i;
    int j;
    t_list *node_i;
    t_list *node_j;

    mistakes = 0;
    total_pairs = 0;
    size = list_size(*head);
    i = 0;
    node_i = *head;
    while (i < size)
    {
        node_j = node_i->next;
        j = i + 1;
        while(j < size)
        {
            total_pairs++;
            if (node_i->data > node_j->data)
                mistakes++;
            j++;
        }
        node_i = node_i->next;
        i++;
    }
    return (mistakes/total_pairs);
}

int main(int argc, char **argv)
{
    t_list  *head_a;
    t_list  *head_b;
    t_list  *node;
    t_list *n;
    int size_a;
    int i;

    if (argc <= 1)
        return (0);

    head_a = NULL;
    head_b = NULL;
    i = 1;
    while(i < argc)
    {
        node = new_node(ft_atoi(argv[i]));
        if (!node)
        {
            free_list(head_a);
            return(0);
        }
        if (i == 1)
            head_a = node;
        else
            add_node_back(head_a, node);
        i++;
    }

    i = 1;
    while(i < argc)
    {
        node = new_node(ft_atoi(argv[i]));
        if (!node)
        {
            free_list(head_b);
            return(0);
        }
        if (i == 1)
            head_b = node;
        else
            add_node_back(head_b, node);
        i++;
    }

    size_a = list_size(head_a);
    printf("before swap-----\n");
    n = head_a;
    while(n)
    {
        printf("num %d\n", n->data);
        n = n->next;
    }
    printf("list size : %d\n", list_size(head_a));
    
    printf("after swap------\n");
    ft_swap(&head_a, size_a);
    n = head_a;
    while(n)
    {
        printf("num %d\n", n->data);
        n = n->next;
    }
    printf("list size : %d\n", list_size(head_a));
    printf("after push------\n");
    ft_push(&head_a, &head_b);
    n = head_a;
    while(n)
    {
        printf("num %d\n", n->data);
        n = n->next;
    }
    printf("list size : %d\n", list_size(head_a));
    printf("after rotation------\n");
    ft_rotate(&head_a);
    n = head_a;
    while(n)
    {
        printf("num %d\n", n->data);
        n = n->next;
    }
    printf("list size : %d\n", list_size(head_a));
    printf("after reversed rotation------\n");
    ft_rotate_reverse(&head_a);
    n = head_a;
    while(n)
    {
        printf("num %d\n", n->data);
        n = n->next;
    }
    printf("list size : %d\n", list_size(head_a));
    printf("disorder : %f\n", compute_disorder(&head_a));

    free_list(head_a);
    free_list(head_b);
    return (0);
}


// int main(int argc, char **argv)
// {
//     int *stack_a;
//     int *stack_b;
//     int i;
    
//     stack_a = malloc(sizeof(int) * (argc - 1));
//     stack_b = malloc(sizeof(int) * (argc - 1));
//     i = 0;
//     while (i < (argc - 1))
//     {
//         stack_a[i] = ft_atoi(argv[i + 1]);
//         i++;
//     }
//     i = 0;
//     while (i < (argc - 1))
//     {
//         printf("num %d\n", stack_a[i]);
//         i++;
//     }
//     return (0);
// }