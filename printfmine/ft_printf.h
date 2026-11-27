/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-idry <hel-idry@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:12:20 by hel-idry          #+#    #+#             */
/*   Updated: 2026/11/06 17:27:09 by hel-idry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>

int		ft_printf(const char *s, ...);
int		ft_print_char(va_list args, char format);
int		ft_print_str(va_list args);
int		ft_print_pointer(va_list args);
int		ft_print_number(va_list args, char format);
int		ft_handle_format(va_list args, char format);
int		ft_putnbr_signed(long long nbr, const char *base);
int		ft_putnbr_base(void *s, const char *base,
			int is_pointer, int is_unsigned);

#endif