NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS =  ft_printf.c\
		ft_printf_parser.c\
		ft_print_char_type.c\
		ft_print_number_type.c\
		ft_print_string_type.c\
		ft_print_percent_type.c\
		ft_print_pointer_type.c\
		ft_print_unsigned_number_type.c\
		ft_print_hex_type.c\

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):
			gcc -c $(CFLAGS) $(SRCS) -I ft_printf.h
			ar rc $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:		fclean all

.PHONY:	all, clean, fclean, re
.SILENT:
