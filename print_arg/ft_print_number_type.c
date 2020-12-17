/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:47:59 by apending          #+#    #+#             */
/*   Updated: 2020/12/14 19:57:02 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_putnbr(int n)
{
	char			c;
	unsigned int	num;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	num = (unsigned int)n;
	if (num >= 10)
	{
		c = (num % 10) + '0';
		ft_putnbr(num / 10);
		write(1, &c, 1);
	}
	else
	{
		c = num + '0';
		write(1, &c, 1);
	}
}

int ft_print_number_type(s_arg s_arg, va_list *arg_ptr)
{
	int num;

	s_arg.type[0] = 'd';
	num = va_arg(*arg_ptr, int);
	ft_putnbr(num);
	return (1);
}
