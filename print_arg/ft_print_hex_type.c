/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:33:32 by apending          #+#    #+#             */
/*   Updated: 2021/01/17 09:10:37 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void ft_print_hex_width_minus(s_arg s_arg, int *print_c)
{
	char width_c;

	width_c = ' ';
	if (!(FLG_MINUS & s_arg.flag) && (s_arg.width - *print_c) > 0)
	{
		if ((FLG_NULL & s_arg.flag) && s_arg.precision == -1)
			width_c = '0';
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
	while ((s_arg.precision - *print_c) > 0 && ++(*print_c))
		write(1, "0", 1);
}

void ft_print_hex(unsigned long num, s_arg s_arg, int *print_c, char c_case)
{
	int hex;
	char c;

	hex = num % 16;
	if (hex < 10)
		c = hex + '0';
	else
		c = hex - 10 + c_case;
	num /= 16;
	(*print_c)++;
	if (num != 0)
		ft_print_hex(num, s_arg, print_c, c_case);
	else
		ft_print_hex_width_minus(s_arg, print_c);
	if (!(s_arg.precision == 0 && c == '0'))
		write(1, &c, 1);
	else
		(*print_c)--;
}

int ft_print_hex_two(s_arg s_arg)
{
	if (s_arg.precision == 0)
		write(1, "  ", 2);
	else
		write(1, "00", 2);
	return (2);
}

int ft_print_hex_type(s_arg s_arg, va_list *arg_ptr, char c_case)
{
	int print_c;
	unsigned long num;

	num = (unsigned long)va_arg(*arg_ptr, unsigned int);
	print_c = 0;
	if (s_arg.precision >= s_arg.width)
		s_arg.width = 0;
	if (s_arg.width == 2 && !num)
		return (ft_print_hex_two(s_arg));
	ft_print_hex(num, s_arg, &print_c, c_case);
	if (!(FLG_MINUS & s_arg.flag) && print_c == s_arg.width - 1
		&& s_arg.precision == 0)
		print_c = s_arg.width;
	if (FLG_MINUS & s_arg.flag)
		while ((s_arg.width - print_c) > 0 && ++print_c)
			write(1, " ", 1);
	return (print_c);
}
