#include "ft_printf.h"

void	ft_print_number_width(t_arg_param param, int *print_c, int sign)
{
	char width_c;

	width_c = ' ';
	if ((FLG_NULL & param.flag) && param.precision == -1)
		width_c = '0';
	if (sign == 1 && (width_c == '0' || param.width == 0) && (sign = -1))
		write(1, sign == 0 ? "+" : "-", 1);
	if (!(FLG_MINUS & param.flag) && (param.width - *print_c) > 0)
	{
		if (*print_c == 1 && param.precision == 0)
			*print_c = 0;
		if ((param.precision - *print_c) > 0)
		{
			param.width -= param.precision - *print_c;
			param.precision += param.width - *print_c;
		}
		while ((param.width - *print_c) > 0 && ++(*print_c))
			write(1, &width_c, 1);
	}
	if (sign > 0)
		write(1, sign == 0 ? "+" : "-", 1);
	while ((param.precision - *print_c) > 0 && ++(*print_c))
		write(1, "0", 1);
}

void	ft_print_number(long int num, t_arg_param param, int *print_c, int sign)
{
	char c;

	c = (num % 10) + '0';
	num /= 10;
	(*print_c)++;
	if (num != 0)
		ft_print_number(num, param, print_c, sign);
	else
		ft_print_number_width(param, print_c, sign);
	if (!(param.precision == 0 && c == '0'))
		write(1, &c, 1);
	else
		(*print_c)--;
}

int		ft_print_number_type(t_arg_param param, va_list *arg_ptr)
{
	int			print_c;
	int			sign;
	long int	num;

	sign = 0;
	print_c = 0;
	num = (int)va_arg(*arg_ptr, int);
	if (num < 0)
	{
		sign = 1;
		num *= -1;
		print_c++;
		if (param.precision != -1)
			param.precision++;
	}
	if (param.precision >= param.width)
		param.width = 0;
	ft_print_number(num, param, &print_c, sign);
	if (!(FLG_MINUS & param.flag) && print_c == param.width - 1
		&& param.precision == 0)
		print_c = param.width;
	if (FLG_MINUS & param.flag)
		while ((param.width - print_c) > 0 && ++print_c)
			write(1, " ", 1);
	return (print_c);
}
