#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define FLG_NONE	0b00000000
# define FLG_MINUS	0b00000001
# define FLG_PLUS	0b00000010
# define FLG_SPACE	0b00000100
# define FLG_SHARP	0b00001000
# define FLG_NULL	0b00010000

typedef	struct	s_args {
	unsigned char	flag;
	int				width;
	int				precision;
	char			type;
}				t_arg_param;

int	ft_strlen(char *str);
int	ft_printf(const char *format, ...);
int	ft_parse_flag(const char *format, int index, t_arg_param *param);
int	ft_parse_width(const char *format, int index, t_arg_param *param,
va_list *arg_ptr);
int	ft_parse_precision(const char *format, int index
, t_arg_param *param, va_list *arg_ptr);
int	ft_parse_type(const char *format, int index, t_arg_param *param);
int	ft_print_arg(t_arg_param param, va_list *arg_ptr);
int	ft_print_char_type(t_arg_param param, va_list *arg_ptr);
int	ft_print_percent_type(t_arg_param param);
int	ft_print_string_type(t_arg_param param, va_list *arg_ptr);
int	ft_print_number_type(t_arg_param param, va_list *arg_ptr);
int	ft_print_pointer_type(t_arg_param param, va_list *arg_ptr);
int	ft_print_unsigned_number_type(t_arg_param param, va_list *arg_ptr);
int	ft_print_hex_type(t_arg_param param, va_list *arg_ptr, char c_case);
#endif
