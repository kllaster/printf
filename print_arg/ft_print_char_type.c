/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:52:39 by apending          #+#    #+#             */
/*   Updated: 2021/01/17 08:56:39 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_print_char_type(s_arg s_arg, va_list *arg_ptr)
{
	int print_c;
	char c;

	print_c = 1;
	c = (char)va_arg(*arg_ptr, int);
	if (s_arg.width == 0)
		s_arg.width = 1;
	--s_arg.width;
	if (FLG_MINUS & s_arg.flag)
		write(1, &c, 1);
	while (--(s_arg.width) >= 0)
	{
		write(1, " ", 1);
		print_c++;
	}
	if (!(FLG_MINUS & s_arg.flag))
		write(1, &c, 1);
	return (print_c);
}
