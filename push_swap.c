
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
void    ft_swap(t_list  **head)
{
    t_list  *tmp;

    if(!(*head) || !(*head)->next)
        return ;
    tmp = (*head)->next;
    (*head)->next = tmp->next;
    tmp->next = *head;
    *head = tmp;
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

void    ft_push(t_list **h1, t_list **h2)
{
    t_list  *tmp;

    if(!(*h2))
        return ;
    tmp = *h2;
    *h2 = (*h2)->next;
    tmp->next = NULL;
    add_front(h1, tmp);
}

void    ft_rotate(t_list **head)
{
    t_list  *last;
    t_list  *next;

    if(!(*head) || !((*head)->next))
        return ;
    last = *head;
    while(last->next)
        last = last->next;
    next = (*head)->next;
    (*head)->next = NULL;
    last->next = *head;
    *head = next;
}

void    ft_reverse_rotate(t_list **head)
{
    t_list  *last;
    t_list  *prev;

    if(!(*head) || !((*head)->next))
        return ;
    last = *head;
    while(last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *head;
    *head = last;
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
    return (head);
}

int main()
{
    t_list  *heada;
    t_list  *headb;
    t_list  *n;
    int tab1[] = {9, 5 , 7, 0, -1};
    int tab2[] = {2, 7 , -8, 1, 20};
    int size1 = sizeof(tab1) / sizeof(int);
    int size2 = sizeof(tab2) / sizeof(int);

    heada = new_list(tab1, 5);
    n = heada;
    printf("----------stack a---------\n");
    printf("top\n");
    while(n)
    {
        printf("node : %d\n", n->data);
        n = n->next;
    }
    printf("bottom\n");

    headb = new_list(tab2, 5);
    n = headb;
    printf("----------stack b---------\n");
    printf("top\n");
    while(n)
    {
        printf("node : %d\n", n->data);
        n = n->next;
    }
    printf("bottom\n");

    printf("----------sa---------\n");
    sa;
    n = heada;
    printf("----------stack a---------\n");
    printf("top\n");
    while(n)
    {
        printf("node : %d\n", n->data);
        n = n->next;
    }
    printf("bottom\n");
    delete_list(heada);
    delete_list(headb);


    return (0);
}

// int main()
// {
//     t_list  *heada;
//     t_list  *headb;
//     t_list  *a1;
//     t_list  *a2;
//     t_list  *a3;
//     t_list  *b1;
//     t_list  *b2;
//     t_list  *b3;
//     t_list *n;

//     heada = new_node(11);
//     a1 = new_node(22);
//     a2 = new_node(33);
//     a3 = new_node(44);
//     headb = new_node(55);
//     b1 = new_node(66);
//     b2 = new_node(77);
//     b3 = new_node(88);
    
//     //stack a
//     add_back(&heada, a1);
//     add_back(&heada, a2);
//     add_back(&heada, a3);

//     //stack b
//     add_back(&headb, b1);
//     add_back(&headb, b2);
//     add_back(&headb, b3);

//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");

//     n = headb;
//     printf("----------stack b---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");



//     printf("-----after push a-----\n");
//     ft_push(&heada, &headb);
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");
//     n = headb;
//     printf("----------stack b---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");
//     printf("-----after rotate a-----\n");
//     ft_rotate(&heada);
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");
//     printf("-----after reverse rotate a-----\n");
//     ft_reverse_rotate(&heada);
//     n = heada;
//     printf("----------stack a---------\n");
//     printf("top\n");
//     while(n)
//     {
//         printf("node : %d\n", n->data);
//         n = n->next;
//     }
//     printf("bottom\n");
//     delete_list(heada);
//     delete_list(headb);

//     return (0);
// }