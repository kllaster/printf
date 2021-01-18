#include "ft_printf.h"

int		ft_print_repeat_char(char c, int len)
{
	int i;

	if (len < 0)
		len = 0;
	i = len;
	while (i-- > 0)
		write(1, &c, 1);
	return (len);
}

void	ft_print_number_width(t_arg_param param, int *print_c, int sign)
{
	char width_c;

	width_c = ' ';
	if ((FLG_NULL & param.flag) && param.precision == -1)
		width_c = '0';
	if (sign == 1 && (width_c == '0' || param.width == 0) && (sign = -1))
		write(1, sign == 0 ? "+" : "-", 1);
	if (!(FLG_MINUS & param.flag))
	{
		if ((param.width - *print_c) > 0)
		{
			if ((param.precision - *print_c) > 0)
			{
				param.width -= param.precision - *print_c;
				param.precision += param.width - *print_c;
			}
			*print_c += ft_print_repeat_char(width_c, (param.width - *print_c));
		}
	}
	if (sign > 0)
		write(1, sign == 0 ? "+" : "-", 1);
	*print_c += ft_print_repeat_char('0', (param.precision - *print_c));
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
	if (num == 0 && param.precision == 0)
		return (ft_print_repeat_char(' ', param.width));
	if (num < 0 && (++print_c))
	{
		sign = 1;
		num *= -1;
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
		print_c += ft_print_repeat_char(' ', (param.width - print_c));
	return (print_c);
}
