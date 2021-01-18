NAME = libftprintf.a
CC = gcc
FLAGS = -c -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c\
	ft_printf_parser.c\
	ft_print_char_type.c\
	ft_print_number_type.c\
	ft_print_string_type.c\
	ft_print_percent_type.c\
	ft_print_pointer_type.c\
	ft_print_unsigned_number_type.c\
	ft_print_hex_type.c\

OBJS = ft_printf.o\
	ft_printf_parser.o\
	ft_print_char_type.o\
	ft_print_number_type.o\
	ft_print_string_type.o\
	ft_print_percent_type.o\
	ft_print_pointer_type.o\
	ft_print_unsigned_number_type.o\
	ft_print_hex_type.o\

.c.o:
	${CC} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CC} ${FLAGS} ${SRC}
			ar -rcs ${NAME} ${OBJS}

all: 		${NAME}

clean:
			rm -rf ${OBJS}

fclean:	clean
			rm -rf libftprintf.a

re: 		fclean all

.PHONY: all clean fclean
