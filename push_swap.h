
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define sa ft_swap(&heada)
#define sb ft_swap(&headb)
#define pa ft_push(&heada, &headb)
#define pb ft_push(&headb, &heada)
#define ra ft_rotate(&heada)
#define rb ft_rotate(&headb)



typedef struct s_list t_list;

typedef struct s_list
{
    int data;
    t_list  *next;
}   t_list;

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


#endif