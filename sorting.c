#include "push_swap.h"

int ft_adaptive(t_list **heada, t_list **headb)
{
    float disorder;

    disorder = compute_disorder(*heada);
    printf("disorder %f\n", disorder);
    if(disorder < 0.2)
        return (insertion_sort(heada, headb));
    else if (disorder >= 0.2 && disorder < 0.5)
        return (bubble_sort(heada, headb));
    else
        return (selection_sort(heada, headb));
}

int ft_sorting(t_list **heada, t_list **headb, t_mode flags)
{
    if (flags == adaptive)
        return (ft_adaptive(heada, headb));
    else if (flags == simple)
        return (insertion_sort(heada, headb));
    else if (flags == medium)
        return (bubble_sort(heada, headb));
    else
        return (selection_sort(heada, headb));
}