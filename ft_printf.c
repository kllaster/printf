/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:45:08 by apending          #+#    #+#             */
/*   Updated: 2020/12/18 19:58:07 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	int				i;
	int				print_res;
	int				print_check_val;
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
			if ((print_check_val =
				ft_printf_parser(format, &i, &arg_ptr)) == -1)
				return (-1);
			if (print_check_val != -2)
			{
				print_res += print_check_val;
				continue ;
			}
		}
		write(1, &(format[i]), 1);
		print_res++;
	}
	va_end(arg_ptr);
	return (print_res);
}
