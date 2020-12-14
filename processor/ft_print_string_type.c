/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:35:30 by apending          #+#    #+#             */
/*   Updated: 2020/12/14 19:47:41 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_print_string_type(s_arg s_arg, va_list *arg_ptr)
{
	int len;
	char *str;

	s_arg.type[0] = 's';
	len = -1;
	str = (char *)va_arg(*arg_ptr, char *);
	while (str[++len])
		write(1, &(str[len]), 1);
	return (len);
}
