#include "push_swap.h"

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


void    add_front(t_list **head, t_list *new)
{
    if (!new)
        return ;
    new->next = *head;
    *head = new;
}

void    add_back(t_list **head, t_list *new)
{
    t_list  *tmp;

    if (!new)
        return ;
    if(!(*head))
    {
        *head = new;
        return ;
    }
    tmp = *head;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void    delete_front(t_list **head)
{
    t_list  *tmp;

    if (!(*head))
        return ;
    tmp = *head;
    *head = (*head)->next;
    free(tmp);

}

void    delete_list(t_list *head)
{
    t_list  *tmp;

    while(head)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

t_list  *new_list(int *tab, int size)
{
    t_list  *head;
    t_list  *node;
    int i;

    i = 0;
    head = NULL;
    if (!tab || size <= 0)
        return (NULL);
    while(i < size)
    {
        node = new_node(tab[i]);
        if (!node)
        {
            delete_list(head);
            return (NULL);
        }
        add_back(&head, node);
        i++;
    }
    // show_list(head);
    return (head);
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

void    show_list(t_list *head)
{
    printf("top : ");
    // ft_putchar("top : ");
    while(head)
    {
        printf("| %d | -> ", head->data);
        head = head->next;
    }
    printf("NULL : bottom\n");
    // ft_putchar("NULL : bottom\n");
}