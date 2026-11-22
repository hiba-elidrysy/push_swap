
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

void    add_front(t_list **head, t_list **new)
{
    if (!*head || !*new)
        return ;
    (*new)->next = *head;
    *head = *new;
}

void    add_back(t_list **head, t_list **new)
{
    t_list  *tmp;

    if (!*head || !*new)
        return ;
    tmp = *head;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = *new;
}

int main()
{
    t_list  *head;
    t_list  *node;
    t_list  *node2;
    t_list  *node3;
    t_list *n;

    head = new_node(11);
    node = new_node(55);
    node2 = new_node(88);
    node3 = new_node(99);
    
    add_front(&head, &node);
    add_front(&head, &node2);
    add_back(&head, &node3);

    n = head;
    while(n)
    {
        printf("node : %d\n", n->data);
        n = n->next;
    }
    return (0);
}