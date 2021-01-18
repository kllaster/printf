#include "ft_printf.h"

int	ft_print_char_type(t_arg_param param, va_list *arg_ptr)
{
	int		print_c;
	char	c;

	print_c = 1;
	c = (char)va_arg(*arg_ptr, int);
	if (param.width == 0)
		param.width = 1;
	--param.width;
	if (FLG_MINUS & param.flag)
		write(1, &c, 1);
	while (--(param.width) >= 0)
	{
		write(1, " ", 1);
		print_c++;
	}
	if (!(FLG_MINUS & param.flag))
		write(1, &c, 1);
	return (print_c);
}
