/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:52:39 by apending          #+#    #+#             */
/*   Updated: 2020/12/17 21:14:21 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_print_char_type(s_arg s_arg, va_list *arg_ptr)
{
	int print_c;
	char c;

	if (s_arg.width == 0)
		s_arg.width = 1;
	print_c = s_arg.width;
	c = (char)va_arg(*arg_ptr, int);
	if (!c)
		c = ' ';
	while (--s_arg.width > 0)
		write(1, &c, 1);
	return (print_c);
}
