#include "ft_printf.h"

void	ft_print_hex_width(t_arg_param param, int *print_c)
{
	char width_c;

	width_c = ' ';
	if (!(FLG_MINUS & param.flag) && (param.width - *print_c) > 0)
	{
		if ((FLG_NULL & param.flag) && param.precision == -1)
			width_c = '0';
		if ((param.precision - *print_c) > 0)
		{
			param.width -= param.precision - *print_c;
			param.precision += param.width - *print_c;
		}
		while ((param.width - *print_c) > 0 && ++(*print_c))
			write(1, &width_c, 1);
	}
	while ((param.precision - *print_c) > 0 && ++(*print_c))
		write(1, "0", 1);
}

void	ft_print_hex(unsigned int num, t_arg_param param, int *print_c,
						char c_case)
{
	int		hex;
	char	c;

	hex = num % 16;
	if (hex < 10)
		c = hex + '0';
	else
		c = hex - 10 + c_case;
	num /= 16;
	(*print_c)++;
	if (num != 0)
		ft_print_hex(num, param, print_c, c_case);
	else
		ft_print_hex_width(param, print_c);
	write(1, &c, 1);
}

int		ft_print_hex_two(t_arg_param param)
{
	if ((FLG_NULL & param.flag) && (FLG_MINUS & param.flag)
		&& param.precision != 0)
		return (write(1, "0 ", 2));
	if (param.precision == 0)
		write(1, "  ", 2);
	else if (param.precision >= -1)
	{
		if ((FLG_NULL & param.flag) && param.precision != 1)
			write(1, "00", 2);
		else
		{
			if ((FLG_MINUS & param.flag))
				write(1, "0 ", 2);
			else
				write(1, " 0", 2);
		}
	}
	else
		write(1, "00", 2);
	return (2);
}

int		ft_print_hex_type(t_arg_param param, va_list *arg_ptr, char c_case)
{
	int				print_c;
	unsigned int	num;

	num = (unsigned int)va_arg(*arg_ptr, unsigned int);
	print_c = 0;
	if (param.precision >= param.width)
		param.width = 0;
	if (!num && param.width == 2)
		return (ft_print_hex_two(param));
	if (num == 0 && param.precision == 0)
		return (ft_print_repeat_char(' ', param.width));
	ft_print_hex(num, param, &print_c, c_case);
	if (!(FLG_MINUS & param.flag) && print_c == param.width - 1
		&& param.precision == 0)
		print_c = param.width;
	if (FLG_MINUS & param.flag)
		while ((param.width - print_c) > 0 && ++print_c)
			write(1, " ", 1);
	return (print_c);
}
