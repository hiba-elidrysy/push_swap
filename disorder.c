#include "push_swap.h"

float compute_disorder(t_list *head)
{
    int mistakes;
    int total_pairs;
    t_list *next;

    mistakes = 0;
    total_pairs = 0;
    next = head->next;

    while(head)
    {
        while(next)
        {
            total_pairs++;
            if(head->data > next->data)
                mistakes++;
            next = next->next;
        }
        head = head->next;
    }
    return ((float)(mistakes / total_pairs));
}