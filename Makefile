# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apending <apending@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/15 21:35:37 by apending          #+#    #+#              #
#    Updated: 2020/12/17 17:59:33 by apending         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =   main_c.c\
		ft_printf.c\
		ft_printf_parser.c\
		print_arg/ft_print_char_type.c\
		print_arg/ft_print_number_type.c\
		print_arg/ft_print_string_type.c\

OBJS = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all, clean, fclean, re
.SILENT:
