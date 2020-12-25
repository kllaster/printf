/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_number_type.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:22:31 by apending          #+#    #+#             */
/*   Updated: 2020/12/25 19:25:10 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_print_unsigned_number_type(s_arg s_arg, va_list *arg_ptr)
{
	int len;
	unsigned int num;
	int print_c;
	char *str;
	char c;

	c = ' ';
	print_c = 0;
	num = va_arg(*arg_ptr, unsigned int);
	if ((FLG_NULL & s_arg.flag) && s_arg.precision == -1)
		c = '0';
	str = ft_itoa(num);
	len = ft_strlen(str);
 	if (FLG_PLUS & s_arg.flag)
		print_c++;
 	if (c == '0' && (FLG_PLUS & s_arg.flag))
		write(1, "+", 1);
	if (!(FLG_MINUS & s_arg.flag))
		print_c = ft_print_width(c, print_c, s_arg, len);
	if (FLG_PLUS & s_arg.flag)
		write(1, "-", 1);
	while (s_arg.precision-- > len)
	{
		write(1, "0", 1);
		print_c++;
	}
	len = -1;
	if (str[0] != '0' || (s_arg.precision != -1 && str[0] == '0'))
	{
		while (str[++len])
		{
			write(1, &(str[len]), 1);
			print_c++;
		}
	}
	else if (s_arg.width > 0)
	{
		write(1, " ", 1);
		print_c++;
	}
	if (FLG_MINUS & s_arg.flag)
		print_c = ft_print_width(c, print_c - len, s_arg, len) + len;
	free(str);
	return (print_c);
}
