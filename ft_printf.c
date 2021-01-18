#include "ft_printf.h"

int	ft_printf_parser(const char *format, int *index, va_list *arg_ptr)
{
	int			old_index;
	int			print_sumb;
	t_arg_param	param;

	print_sumb = 0;
	old_index = *index;
	*index += 1;
	if (format[*index] == '%' && (write(1, "%", 1)))
		return (1);
	if ((*index = ft_parse_flag(format, *index, &param)) == -1)
		return (-1);
	if ((*index = ft_parse_width(format, *index, &param, arg_ptr)) == -1)
		return (-1);
	if ((*index = ft_parse_precision(format, *index, &param, arg_ptr)) == -1)
		return (-1);
	if ((*index = ft_parse_type(format, *index, &param)) == -1)
		return (-1);
	if ((print_sumb = ft_print_arg(param, arg_ptr)) == -2)
	{
		*index = old_index;
		return (-2);
	}
	else if (param.type == ' ')
		return (-1);
	return (print_sumb);
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				print_res;
	int				check_val;
	va_list			arg_ptr;

	if (!format)
		return (0);
	va_start(arg_ptr, format);
	print_res = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if ((check_val = ft_printf_parser(format, &i, &arg_ptr)) == -1)
				return (0);
			if (check_val != -2 && ((print_res += check_val) || print_res == 0))
				continue ;
		}
		write(1, &(format[i]), 1);
		print_res++;
	}
	va_end(arg_ptr);
	return (print_res);
}
