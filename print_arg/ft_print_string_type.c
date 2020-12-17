/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:35:30 by apending          #+#    #+#             */
/*   Updated: 2020/12/17 18:00:16 by apending         ###   ########.fr       */
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

char	*ft_strdup(const char *str)
{
	char	*res;
	char	*p;
	size_t	size;

	size = (size_t)ft_strlen((char*)str) + 1;
	if (!(res = malloc(size * sizeof(char))))
		return (0);
	p = res;
	while (*str)
	{
		*res = *str;
		str++;
		res++;
	}
	*res = 0;
	return (p);
}

int ft_print_string_type(s_arg s_arg, va_list *arg_ptr)
{
	int len;
	int free_null;
	char *str;

	free_null = 0;
	str = va_arg(*arg_ptr, char *);
	if (str == NULL)
	{
		free_null = 1;
		str = ft_strdup("(null)");
	}
	len = ft_strlen(str);
	if (s_arg.precision != -1 && s_arg.precision < len)
		len = s_arg.precision;
	if (s_arg.width > len)
	{
		if (!(s_arg.flag & FLG_MINUS))
		{
			len = s_arg.width - len;
			while (len--)
				write(1, " ", 1);
		}
		len = -1;
		while (str[++len])
		{
			if (s_arg.precision == len)
				break ;
			write(1, &(str[len]), 1);
		}
		if (s_arg.flag & FLG_MINUS)
		{
			len = s_arg.width - len;
			while (len--)
				write(1, " ", 1);
		}
		if (free_null)
			free(str);
		return (s_arg.width);
	}
	len = -1;
	while (str[++len])
	{
		if (s_arg.precision == len)
			break ;
		write(1, &(str[len]), 1);
	}
	return (len);
}
