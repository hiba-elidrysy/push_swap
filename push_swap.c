#include "push_swap.h"

int    ft_swap(t_list  **head, int c)
{
    t_list  *tmp;

    if(!(*head) || !(*head)->next)
        return 0;
    tmp = (*head)->next;
    (*head)->next = tmp->next;
    tmp->next = *head;
    *head = tmp;
    if (c == 'a')
        ft_putchar("sa\n");
    else if (c == 'b')
        ft_putchar("sb\n");
    return (1);
}


int    ft_push(t_list **h1, t_list **h2, int c)
{
    t_list  *tmp;

    if(!(*h2))
        return (0);
    tmp = *h2;
    *h2 = (*h2)->next;
    tmp->next = NULL;
    add_front(h1, tmp);
    if (c == 'a')
        ft_putchar("pa\n");
    else if (c == 'b')
        ft_putchar("pb\n");
    return (1);
}

int    ft_rotate(t_list **head, int c)
{
    t_list  *last;
    t_list  *next;

    if(!(*head) || !((*head)->next))
        return (0);
    last = *head;
    while(last->next)
        last = last->next;
    next = (*head)->next;
    (*head)->next = NULL;
    last->next = *head;
    *head = next;
    if (c == 'a')
        ft_putchar("ra\n");
    else if (c == 'b')
        ft_putchar("rb\n");
    return (1);
}

int    ft_reverse_rotate(t_list **head, int c)
{
    t_list  *last;
    t_list  *prev;

    if(!(*head) || !((*head)->next))
        return (0);
    last = *head;
    while(last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *head;
    *head = last;
    if (c == 'a')
        ft_putchar("rra\n");
    else if (c == 'b')
        ft_putchar("rrb\n");
    return (1);
}

