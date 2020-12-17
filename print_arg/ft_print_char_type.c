/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:52:39 by apending          #+#    #+#             */
/*   Updated: 2020/12/17 18:00:10 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_print_char_type(va_list *arg_ptr)
{
	char c;

	c = (char)va_arg(*arg_ptr, int);
	write(1, &c, 1);
	return (1);
}
