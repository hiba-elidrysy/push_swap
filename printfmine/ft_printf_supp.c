/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_supp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-idry <hel-idry@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 17:11:56 by hel-idry          #+#    #+#             */
/*   Updated: 2026/11/07 20:20:02 by hel-idry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args, char format)
{
	char	c;

	if (format == '%')
		c = '%';
	else
		c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(va_list args)
{
	char	*str;
	int		count;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	count = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

int	ft_print_pointer(va_list args)
{
	void	*p;
	int		count;

	p = va_arg(args, void *);
	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = 2;
	count += ft_putnbr_base(p, "0123456789abcdef", 1, 0);
	return (count);
}

int	ft_print_number(va_list args, char format)
{
	unsigned long long	u_d;
	long long			d;

	if (format == 'd' || format == 'i')
	{
		d = va_arg(args, int);
		return (ft_putnbr_base(&d, "0123456789", 0, 0));
	}
	u_d = va_arg(args, unsigned int);
	if (format == 'u')
		return (ft_putnbr_base(&u_d, "0123456789", 0, 1));
	if (format == 'x')
		return (ft_putnbr_base(&u_d, "0123456789abcdef", 0, 1));
	return (ft_putnbr_base(&u_d, "0123456789ABCDEF", 0, 1));
}

int	ft_handle_format(va_list args, char format)
{
	if (format == 'c' || format == '%')
		return (ft_print_char(args, format));
	else if (format == 's')
		return (ft_print_str(args));
	else if (format == 'p')
		return (ft_print_pointer(args));
	else if (format == 'd' || format == 'i' || format == 'u'
		|| format == 'x' || format == 'X')
		return (ft_print_number(args, format));
	else
		return (-1);
	write(1, "%", 1);
	write(1, &format, 1);
	return (2);
}
