# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apending <apending@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/15 21:35:37 by apending          #+#    #+#              #
#    Updated: 2020/12/18 20:00:49 by apending         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
LIB = ar rc
CFLAGS_TEST = -Wall -Wextra
SRC =   main.c\
		ft_printf.c\
		ft_printf_parser.c\
		print_arg/ft_print_char_type.c\
		print_arg/ft_print_number_type.c\
		print_arg/ft_print_string_type.c\
		print_arg/ft_print_percent_type.c\

OBJS = $(SRC:.c=.o)


all:	bild

test: $(OBJS)
		$(CC) $(CFLAGS_TEST) -o $(NAME) $(OBJS)

bild: $(OBJS)
		$(LIB) $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all, clean, fclean, re
.SILENT:
