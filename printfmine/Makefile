# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-idry <hel-idry@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/26 18:56:23 by hel-idry          #+#    #+#              #
#    Updated: 2026/11/05 17:19:16 by hel-idry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

AR          = ar rcs
RM          = rm -f

HEADERS     = ft_printf.h

SRCS        = ft_printf.c ft_printf_supp.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
