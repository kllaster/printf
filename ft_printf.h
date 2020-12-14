/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:24:20 by apending          #+#    #+#             */
/*   Updated: 2020/12/14 19:48:44 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define FLG_NONE	0b00000000
#define FLG_MINUS	0b00000001
#define FLG_PLUS	0b00000010
#define FLG_SPACE	0b00000100
#define FLG_SHARP	0b00001000
#define FLG_NULL	0b00010000

typedef	struct	struct_args {
	unsigned char	flag;
	int				notation;
	int				width;
	int				precision;
	int				type_found;
	char			type[10];
} s_arg;

int	ft_printf_parser(const char *format, int *index, va_list *arg_ptr);
int ft_print_char_type(va_list *arg_ptr);
int ft_print_string_type(s_arg s_arg, va_list *arg_ptr);
int ft_print_number_type(s_arg s_arg, va_list *arg_ptr);
