/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:35:30 by apending          #+#    #+#             */
/*   Updated: 2021/01/17 01:02:11 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_print_string_type(s_arg s_arg, va_list *arg_ptr)
{
	int print_c;
	int len;
	char *str;

	print_c = 0;
	str = va_arg(*arg_ptr, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (s_arg.precision != -1 && s_arg.precision < len)
		len = s_arg.precision;
	if ((s_arg.width > len) && !(s_arg.flag & FLG_MINUS))
	{
		s_arg.width -= len;
		print_c += s_arg.width;
		while (s_arg.width--)
			write(1, " ", 1);
	}
	len = -1;
	while (str[++len])
	{
		if (s_arg.precision == len)
			break ;
		write(1, &(str[len]), 1);
		++print_c;
	}
	if ((s_arg.width > len) && (s_arg.flag & FLG_MINUS))
	{
		s_arg.width -= len;
		print_c += s_arg.width;
		while (s_arg.width--)
			write(1, " ", 1);
	}
	return (print_c);
}
