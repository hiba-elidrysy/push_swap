
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "printfmine/ft_printf.h"


#define sa sa(&heada, &headb);
#define sb sb(&heada, &headb);
#define ss ss(&heada, &headb);
#define pa pa(&heada, &headb);
#define pb pb(&heada, &headb);
#define pp pp(&heada, &headb);
#define ra ra(&heada, &headb);
#define rb rb(&heada, &headb);
#define rr rr(&heada, &headb);
#define rra rra(&heada, &headb);
#define rrb rrb(&heada, &headb);
#define rrr rrr(&heada, &headb);


typedef struct s_list t_list;

typedef struct s_list
{
    int data;
    t_list  *next;
}   t_list;

typedef enum s_mode
{
    adaptive,
    simple,
    medium,
    complex
}   t_mode;

t_list  *new_node(int data);
t_list  *new_list(int *tab, int size);
void    add_front(t_list **head, t_list *new);
void    add_back(t_list **head, t_list *new);
int    ft_swap(t_list  **head, int c);
void    delete_front(t_list **head);
int    ft_push(t_list **h1, t_list **h2, int c);
int    ft_rotate(t_list **head, int c);
int    ft_reverse_rotate(t_list **head, int c);
void    delete_list(t_list *head);
int list_size(t_list *head);
int ft_strlen(const char *str);
char *ft_strjoin(const char **str, int count, int pos);
char    **ft_split(const char *str);
void ft_putchar(const char *str);
int ft_atoi(const char *str);
char    **ft_split(const char *str);
void    show_list(t_list *head);
int count_char_numbers(const char *str);
int ft_strcmp(const char *s1, const char *s2);

// sorts
int insertion_sort(t_list **heada, t_list **headb);
int selection_sort(t_list **heada, t_list **headb);
int bubble_sort(t_list **heada, t_list **headb);

int is_flag(char *str);
int ft_adaptive(t_list **heada, t_list **headb);
int ft_sorting(t_list **heada, t_list **headb, t_mode flags);
float compute_disorder(t_list *head);


// operations
int sa(t_list **heada, t_list **headb);
int sb(t_list **heada, t_list **headb);
int ss(t_list **heada, t_list **headb);
int pa(t_list **heada, t_list **headb);
int pb(t_list **heada, t_list **headb);
int pp(t_list **heada, t_list **headb);
int ra(t_list **heada, t_list **headb);
int rb(t_list **heada, t_list **headb);
int rr(t_list **heada, t_list **headb);
int rra(t_list **heada, t_list **headb);
int rrb(t_list **heada, t_list **headb);
int rrr(t_list **heada, t_list **headb);


#endif