/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-idry <hel-idry@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:53:27 by hel-idry          #+#    #+#             */
/*   Updated: 2026/11/06 17:27:25 by hel-idry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

static int	putnbr_convert(unsigned long long nbr, const char *base)
{
	unsigned long long	len;
	int					count;

	count = 0;
	len = ft_strlen(base);
	if (nbr >= len)
		count += putnbr_convert(nbr / len, base);
	write(1, &base[nbr % len], 1);
	return (1 + count);
}

int	ft_putnbr_signed(long long nbr, const char *base)
{
	unsigned long long	n;
	int					count;

	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		n = (unsigned long long)(-(nbr + 1)) + 1;
	}
	else
		n = (unsigned long long)nbr;
	return (count + putnbr_convert(n, base));
}

int	ft_putnbr_base(void *s, const char *base,
		int is_pointer, int is_unsigned)
{
	long long			*nbr;
	unsigned long long	*unbr;
	int					count;

	count = 0;
	if (is_pointer)
		count = putnbr_convert((uintptr_t)s, base);
	else if (is_unsigned)
	{
		unbr = (unsigned long long *)s;
		count = putnbr_convert(*unbr, base);
	}
	else
	{
		nbr = (long long *)s;
		count = ft_putnbr_signed(*nbr, base);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			count += ft_handle_format(args, *(s + 1));
			s += 2;
		}
		else
		{
			write(1, s, 1);
			count++;
			s++;
		}
	}
	va_end(args);
	return (count);
}
