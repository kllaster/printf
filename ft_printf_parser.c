/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:28:19 by apending          #+#    #+#             */
/*   Updated: 2020/12/24 20:41:05 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_parse_flag(const char *format, int index, s_arg *s_arg)
{
	int i;

	i = 0;
	(*s_arg).flag = FLG_NONE;
	while (format[index + i])
	{
		if (format[index + i] == '-')
			(*s_arg).flag |= FLG_MINUS;
		else if (format[index + i] == '+')
			(*s_arg).flag |= FLG_PLUS;
		else if (format[index + i] == ' ')
			(*s_arg).flag |= FLG_SPACE;
		else if (format[index + i] == '#')
			(*s_arg).flag |= FLG_SHARP;
		else if (format[index + i] == '0')
			(*s_arg).flag |= FLG_NULL;
		else
		{
			i--;
			break ;
		}
		i++;
	}
	return (index + i);
}

int	ft_parse_width(const char *format, int index, s_arg *s_arg, va_list *arg_ptr)
{
	int width;

	index++;
	width = 0;
	if (format[index] && format[index] == '*')
	{
		(*s_arg).width = va_arg(*arg_ptr, int);
		if ((*s_arg).width < 0)
		{
			(*s_arg).width *= -1;
			(*s_arg).flag |= FLG_MINUS;
		}
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
	(*s_arg).width = width;
	return (--index);
}

int	ft_parse_precision(const char *format, int index, s_arg *s_arg, va_list *arg_ptr)
{
	int precision;

	index++;
	precision = 0;
	if (format[index] && format[index] == '.')
	{
		index++;
		if (format[index] == '*')
		{
			(*s_arg).precision = va_arg(*arg_ptr, int);
			if ((*s_arg).precision < 0)
				(*s_arg).precision = -1;
			return (index);
		}
		while (format[index])
		{
			if (format[index] >= '0' && format[index] <= '9')
				precision = (precision * 10) + format[index] - '0';
			else
				break ;
			index++;
		}
		(*s_arg).precision = precision;
	}
	else
		(*s_arg).precision = -1;
	return (--index);
}

int	ft_parse_type(const char *format, int index, s_arg *s_arg)
{
	int i;

	i = 0;
	index++;
	if (format[index])
	{
		if (format[index] == 'd' || format[index] == 'i')
			(*s_arg).type[i++] = 'd';
		else if (format[index] == 'c' ||
					format[index] == 'x' ||
					format[index] == 'X' ||
					format[index] == 'o' ||
					format[index] == 'u' ||
					format[index] == 's' ||
					format[index] == 'S' ||
					format[index] == 'p')
			(*s_arg).type[i++] = format[index];
		(*s_arg).type[i] = '\0';
	}
	if (i == 0 && ((*s_arg).precision != -1 || (*s_arg).width > 0))
	{
		(*s_arg).type[i++] = '%';
		(*s_arg).type[i] = '\0';
	}
	return (index);
}

int	ft_print_arg(s_arg s_arg, va_list *arg_ptr)
{
	int print_sumb;

	print_sumb = -2;
	if (s_arg.type[0] == 'c')
		print_sumb = ft_print_char_type(s_arg, arg_ptr);
	else if (s_arg.type[0] == '%')
		print_sumb = ft_print_percent_type(s_arg);
	else if (s_arg.type[0] == 's')
		print_sumb = ft_print_string_type(s_arg, arg_ptr);
	else if (s_arg.type[0] == 'd')
		print_sumb = ft_print_number_type(s_arg, arg_ptr);
	return (print_sumb);
}

int	ft_printf_parser(const char *format, int *index, va_list *arg_ptr)
{
	int		old_index;
	int		print_sumb;
	s_arg	s_arg;

	print_sumb = 0;
	old_index = *index;
	*index += 1;
	if (format[*index] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if ((*index = ft_parse_flag(format, *index, &s_arg)) == -1)
		return (-1);
	if ((*index = ft_parse_width(format, *index, &s_arg, arg_ptr)) == -1)
		return (-1);
	if ((*index = ft_parse_precision(format, *index, &s_arg, arg_ptr)) == -1)
		return (-1);
	if ((*index = ft_parse_type(format, *index, &s_arg)) == -1)
		return (-1);
	if ((print_sumb = ft_print_arg(s_arg, arg_ptr)) == -2)
	{
		*index = old_index;
		return (-2);
	}
	return (print_sumb);
}
