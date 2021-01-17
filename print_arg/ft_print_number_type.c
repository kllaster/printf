/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:47:59 by apending          #+#    #+#             */
/*   Updated: 2021/01/17 10:46:43 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void ft_print_number_width(s_arg s_arg, int *print_c, int sign)
{
	char width_c;

	width_c = ' ';
	if ((FLG_NULL & s_arg.flag) && s_arg.precision == -1)
		width_c = '0';
	if (sign == 1 && (width_c == '0' || s_arg.width == 0))
	{
		write(1, sign == 0 ? "+" : "-", 1);
		sign = -1;
	}
	if (!(FLG_MINUS & s_arg.flag) && (s_arg.width - *print_c) > 0)
	{
		if (*print_c == 1 && s_arg.precision == 0)
			*print_c = 0;
		if ((s_arg.precision - *print_c) > 0)
		{
			s_arg.width -= s_arg.precision - *print_c;
			s_arg.precision += s_arg.width - *print_c;
		}
		while ((s_arg.width - *print_c) > 0 && ++(*print_c))
			write(1, &width_c, 1);
	}
	if (sign > 0)
		write(1, sign == 0 ? "+" : "-", 1);
	while ((s_arg.precision - *print_c) > 0 && ++(*print_c))
		write(1, "0", 1);
}

void ft_print_number(long int num, s_arg s_arg, int *print_c, int sign)
{
	char c;

	c = (num % 10) + '0';
	num /= 10;
	(*print_c)++;
	if (num != 0)
		ft_print_number(num, s_arg, print_c, sign);
	else
		ft_print_number_width(s_arg, print_c, sign);
	if (!(s_arg.precision == 0 && c == '0'))
		write(1, &c, 1);
	else
		(*print_c)--;
}

int ft_print_number_type(s_arg s_arg, va_list *arg_ptr)
{
	int print_c;
	int sign;
	long int num;

	sign = 0;
	print_c = 0;
	num = (int)va_arg(*arg_ptr, int);
	if (num < 0)
	{
		sign = 1;
		num *= -1;
		print_c++;
		if (s_arg.precision != -1)
			s_arg.precision++;
	}
	if (s_arg.precision >= s_arg.width)
		s_arg.width = 0;
	ft_print_number(num, s_arg, &print_c, sign);
	if (!(FLG_MINUS & s_arg.flag) && print_c == s_arg.width - 1
		&& s_arg.precision == 0)
		print_c = s_arg.width;
	if (FLG_MINUS & s_arg.flag)
		while ((s_arg.width - print_c) > 0 && ++print_c)
			write(1, " ", 1);
	return (print_c);
}
