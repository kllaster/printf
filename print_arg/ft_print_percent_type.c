/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 20:43:05 by apending          #+#    #+#             */
/*   Updated: 2020/12/17 21:07:55 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_print_percent_type(s_arg s_arg)
{
	int print_c;
	char c;

	c = ' ';
	if (s_arg.width == 0)
		s_arg.width = 1;
	print_c = s_arg.width;
	if (s_arg.flag & FLG_MINUS)
		write(1, "%", 1);
	else if (s_arg.flag & FLG_NULL)
		c = '0';
	while (--s_arg.width > 0)
		write(1, &c, 1);
	if (!(s_arg.flag & FLG_MINUS))
		write(1, "%", 1);
	return (print_c);
}
