#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_string_width(t_arg_param param, int len, int print_c)
{
	char width_c;

	width_c = ' ';
	if (FLG_NULL & param.flag)
		width_c = '0';
	param.width -= len;
	print_c += param.width;
	while (param.width--)
		write(1, &width_c, 1);
	return (print_c);
}

int	ft_print_string_type(t_arg_param param, va_list *arg_ptr)
{
	int		print_c;
	int		len;
	char	*str;

	print_c = 0;
	str = va_arg(*arg_ptr, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (param.precision != -1 && param.precision < len)
		len = param.precision;
	if (!(param.flag & FLG_MINUS) && (param.width > len))
		print_c = ft_print_string_width(param, len, print_c);
	len = -1;
	while (str[++len])
	{
		if (param.precision == len)
			break ;
		write(1, &(str[len]), 1);
		++print_c;
	}
	if ((param.width > len) && (param.flag & FLG_MINUS) && (param.flag &= ~FLG_NULL))
		print_c = ft_print_string_width(param, len, print_c);
	return (print_c);
}
