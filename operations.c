#include "push_swap.h"

// swaping
int sa(t_list **heada, t_list **headb)
{
    return (ft_swap(heada, 'a'));
}

int sb(t_list **heada, t_list **headb)
{
    return (ft_swap(headb, 'b'));
}

int ss(t_list **heada, t_list **headb)
{
    ft_printf("ss\n");
    return (ft_swap(heada, 0) && ft_swap(headb, 0));
}

// pushing
int pa(t_list **heada, t_list **headb)
{
    return (ft_push(heada, headb, 'a'));
}

int pb(t_list **heada, t_list **headb)
{
    return (ft_push(headb, heada, 'b'));
}

int pp(t_list **heada, t_list **headb)
{
    ft_printf("pp\n");
    return (ft_push(heada, headb, 0) && ft_push(headb, heada, 0));
}

// rotating
int ra(t_list **heada, t_list **headb)
{
    return (ft_rotate(heada, 'a'));
}

int rb(t_list **heada, t_list **headb)
{
    return (ft_rotate(headb, 'b'));
}

int rr(t_list **heada, t_list **headb)
{
    ft_printf("rr\n");
    return (ft_rotate(heada, 0) && ft_rotate(headb, 0));
}

// reversed rotating
int rra(t_list **heada, t_list **headb)
{
    return (ft_reverse_rotate(heada, 'a'));
}

int rrb(t_list **heada, t_list **headb)
{
    return (ft_reverse_rotate(headb, 'b'));
}

int rrr(t_list **heada, t_list **headb)
{
    ft_printf("rrr\n");
    return (ft_reverse_rotate(heada, 0) && ft_reverse_rotate(headb, 0));
}