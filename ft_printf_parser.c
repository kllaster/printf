#include "ft_printf.h"

int	ft_parse_flag(const char *format, int index, t_arg_param *param)
{
	int i;

	i = 0;
	(*param).flag = FLG_NONE;
	while (format[index + i])
	{
		if (format[index + i] == '-')
			(*param).flag |= FLG_MINUS;
		else if (format[index + i] == '+')
			(*param).flag |= FLG_PLUS;
		else if (format[index + i] == ' ')
			(*param).flag |= FLG_SPACE;
		else if (format[index + i] == '#')
			(*param).flag |= FLG_SHARP;
		else if (format[index + i] == '0')
			(*param).flag |= FLG_NULL;
		else
		{
			i--;
			break ;
		}
		i++;
	}
	return (index + i);
}

int	ft_parse_width(const char *format, int index, t_arg_param *param,
					va_list *arg_ptr)
{
	int width;

	index++;
	width = 0;
	if (format[index] && format[index] == '*')
	{
		(*param).width = va_arg(*arg_ptr, int);
		if ((*param).width < 0 && ((*param).width *= -1))
			(*param).flag |= FLG_MINUS;
		return (index);
	}
	while (format[index])
	{
		if (format[index] >= '0' && format[index] <= '9')
			width = (width * 10) + format[index] - '0';
		else
			break ;
		index++;
	}
	(*param).width = width;
	return (--index);
}

int	ft_parse_precision(const char *format, int index, t_arg_param *param,
						va_list *arg_ptr)
{
	index++;
	(*param).precision = 0;
	if (format[index] && format[index] == '.' && (++index))
	{
		if (format[index] && format[index] == '*')
		{
			(*param).precision = va_arg(*arg_ptr, int);
			if ((*param).precision < 0)
				(*param).precision = -1;
			return (index);
		}
		while (format[index])
		{
			if (format[index] >= '0' && format[index] <= '9')
				(*param).precision = ((*param).precision * 10)
										+ format[index] - '0';
			else
				break ;
			index++;
		}
	}
	else
		(*param).precision = -1;
	return (--index);
}

int	ft_parse_type(const char *format, int index, t_arg_param *param)
{
	index++;
	(*param).type = ' ';
	if (format[index])
	{
		if (format[index] == 'd' || format[index] == 'i' ||
			format[index] == 'c' || format[index] == 'x' ||
			format[index] == 'X' || format[index] == 'o' ||
			format[index] == 'u' || format[index] == 's' ||
			format[index] == 'S' || format[index] == 'p' ||
			format[index] == '%')
			(*param).type = format[index];
	}
	return (index);
}

int	ft_print_arg(t_arg_param param, va_list *arg_ptr)
{
	int print_sumb;

	print_sumb = -2;
	if (param.type == 'c')
		print_sumb = ft_print_char_type(param, arg_ptr);
	else if (param.type == '%')
		print_sumb = ft_print_percent_type(param);
	else if (param.type == 's')
		print_sumb = ft_print_string_type(param, arg_ptr);
	else if (param.type == 'd' || param.type == 'i')
		print_sumb = ft_print_number_type(param, arg_ptr);
	else if (param.type == 'u')
		print_sumb = ft_print_unsigned_number_type(param, arg_ptr);
	else if (param.type == 'p')
		print_sumb = ft_print_pointer_type(param, arg_ptr);
	else if (param.type == 'x')
		print_sumb = ft_print_hex_type(param, arg_ptr, 'a');
	else if (param.type == 'X')
		print_sumb = ft_print_hex_type(param, arg_ptr, 'A');
	else if (param.type == ' ')
		print_sumb = 0;
	return (print_sumb);
}
