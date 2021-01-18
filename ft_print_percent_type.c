#include "ft_printf.h"

int	ft_print_percent_type(t_arg_param param)
{
	int		print_c;
	char	c;

	c = ' ';
	if (param.width == 0)
		param.width = 1;
	print_c = param.width;
	if (param.flag & FLG_MINUS)
		write(1, "%", 1);
	else if (param.flag & FLG_NULL)
		c = '0';
	while (--param.width > 0)
		write(1, &c, 1);
	if (!(param.flag & FLG_MINUS))
		write(1, "%", 1);
	return (print_c);
}
