/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:33:32 by apending          #+#    #+#             */
/*   Updated: 2020/12/25 21:51:23 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void ft_print_hex(unsigned int num, s_arg s_arg, char c_case, int *print_c)
{
	char c;
	unsigned int hex;

	hex = num % 16;
	if (hex < 10)
		c = hex + '0';
	else
		c = hex - 10 + c_case;
	num /= 16;
	(*print_c)++;
	if (num != 0)
		ft_print_hex(num, s_arg, c_case, print_c);
	else
	{
	}
	write(1, &c, 1);
}

int		ft_print_hex_type(s_arg s_arg, va_list *arg_ptr, char c_case)
{
	int print_c;
	unsigned int num;

	num = va_arg(*arg_ptr, unsigned int);
	print_c = 0;
	if (s_arg.precision > s_arg.width)
		s_arg.width = 0;
	ft_print_hex(num, s_arg, c_case, &print_c);
	if (!(FLG_MINUS & s_arg.flag) && print_c == s_arg.width - 1 && s_arg.precision == 0)
		print_c = s_arg.width;
	if (FLG_MINUS & s_arg.flag)
	{
		while ((s_arg.width - print_c) > 0)
		{
			write(1, " ", 1);
			print_c++;
		}
	}
	return (print_c);
}
