/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:45:08 by apending          #+#    #+#             */
/*   Updated: 2021/01/17 11:29:24 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
