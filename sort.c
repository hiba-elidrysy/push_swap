#include "push_swap.h"

//version 1

// static int	find_target(t_list *b, int x)
// {
// 	int	target;
// 	int	max;
// 	int	found;

// 	found = 0;
// 	target = b->data;
// 	max = b->data;
// 	while (b)
// 	{
// 		if (b->data > max)
// 			max = b->data;
// 		if (b->data < x && (!found || b->data > target))
// 		{
// 			target = b->data;
// 			found = 1;
// 		}
// 		b = b->next;
// 	}
// 	if (!found)
// 		return (max);
// 	return (target);
// }

// static int	find_max(t_list *b)
// {
// 	int	max;

// 	max = b->data;
// 	while (b)
// 	{
// 		if (b->data > max)
// 			max = b->data;
// 		b = b->next;
// 	}
// 	return (max);
// }

// static int	index_of(t_list *b, int value)
// {
// 	int	i;

// 	i = 0;
// 	while (b && b->data != value)
// 	{
// 		b = b->next;
// 		i++;
// 	}
// 	return (i);
// }

// static int	rotate_to(t_list **b, int idx)
// {
// 	int	size;
// 	int	ops;

// 	size = list_size(*b);
// 	ops = 0;
// 	if (idx <= size / 2)
// 	{
// 		while (idx-- > 0)
// 			ops += ft_rotate(b, 'b');
// 	}
// 	else
// 	{
// 		idx = size - idx;
// 		while (idx-- > 0)
// 			ops += ft_reverse_rotate(b, 'b');
// 	}
// 	return (ops);
// }

// int	insertion_sort(t_list **a, t_list **b)
// {
// 	int	ops;

// 	ops = 0;
// 	if (*a)
// 		ops += ft_push(b, a, 'b');
// 	while (*a)
// 	{
// 		ops += rotate_to(b, index_of(*b, find_target(*b, (*a)->data)));
// 		ops += ft_push(b, a, 'b');
// 	}
// 	if (*b)
// 		ops += rotate_to(b, index_of(*b, find_max(*b)));
// 	while (*b)
// 		ops += ft_push(a, b, 'a');
// 	return (ops);
// }



// version 2

static int	last_data(t_list *b)
{
	while (b->next)
		b = b->next;
	return (b->data);
}

static int	fits(t_list *b, int x)
{
	int	last;

	last = last_data(b);
	if (last > b->data)
		return (last >= x && x >= b->data);
	return (x >= b->data || x <= last);
}

int	insertion_sort(t_list **heada, t_list **headb)
{
	int	ops;

	ops = 0;
	if (*heada)
		ops += ft_push(headb, heada, 'b');
	while (*heada)
	{
		while (!fits(*headb, (*heada)->data))
			ops += ft_rotate(headb, 'b');
		ops += ft_push(headb, heada, 'b');
	}
	while (*headb && last_data(*headb) > (*headb)->data)
		ops += ft_rotate(headb, 'b');
	while (*headb)
		ops += ft_push(heada, headb, 'a');
	return (ops);
}