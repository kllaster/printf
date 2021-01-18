#include "ft_printf.h"

void	ft_print_pointer_width(t_arg_param param, int *print_c)
{
	int start_chars;

	start_chars = 0;
	if (((param.precision - *print_c) > 0 ||
		(FLG_MINUS & param.flag) || (param.width - (*print_c) - 2) < 0)
		&& (start_chars = 1))
		write(1, "0x", 2);
	while ((param.precision - *print_c) > 0)
	{
		write(1, "0", 1);
		(*print_c)++;
	}
	if (!(FLG_MINUS & param.flag) && (param.width - (*print_c)) > 0)
	{
		if (*print_c == 1 && param.precision == 0)
			*print_c = 0;
		while ((param.width - (*print_c) - 2) > 0)
		{
			write(1, " ", 1);
			(*print_c)++;
		}
		if (start_chars == 0)
			write(1, "0x", 2);
	}
	(*print_c) += 2;
}

void	ft_print_pointer(unsigned long num, t_arg_param param, int *print_c)
{
	int		hex;
	char	c;

	hex = num % 16;
	if (hex < 10)
		c = hex + '0';
	else
		c = hex - 10 + 'a';
	num /= 16;
	(*print_c)++;
	if (num != 0)
		ft_print_pointer(num, param, print_c);
	else
		ft_print_pointer_width(param, print_c);
	if (!(param.precision == 0 && c == '0'))
		write(1, &c, 1);
	else
		(*print_c)--;
}

int		ft_print_pointer_two(t_arg_param param)
{
	write(1, "0x", 2);
	if (!param.precision)
		return (2);
	else
		write(1, "0", 1);
	return (3);
}

int		ft_print_pointer_type(t_arg_param param, va_list *arg_ptr)
{
	int				print_c;
	unsigned long	num;

	num = (unsigned long)va_arg(*arg_ptr, void*);
	print_c = 0;
	if (param.precision > param.width)
		param.width = 0;
	if (param.width == 2 && !num)
		return (ft_print_pointer_two(param));
	ft_print_pointer(num, param, &print_c);
	if (!(FLG_MINUS & param.flag) && print_c == param.width - 1
			&& param.precision == 0)
		print_c = param.width;
	if (FLG_MINUS & param.flag)
	{
		while ((param.width - print_c) > 0)
		{
			write(1, " ", 1);
			print_c++;
		}
	}
	return (print_c);
}
