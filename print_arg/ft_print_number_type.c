/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:47:59 by apending          #+#    #+#             */
/*   Updated: 2020/12/17 23:41:24 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_numlen(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*ft_getres(char *res, unsigned int num, int len, int flag)
{
	if (!num)
		res[0] = '0';
	else
	{
		while (num)
		{
			res[--len] = (num % 10) + '0';
			num /= 10;
		}
		if (flag)
			res[0] = '-';
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char			*res;
	int				flag;
	int				len;
	unsigned int	num;

	len = ft_numlen(n);
	flag = 0;
	if (n < 0 || !n)
	{
		if (n < 0)
			flag = 1;
		len += 1;
		n *= -1;
	}
	num = (unsigned int)n;
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (0);
	res[len] = 0;
	return (ft_getres(res, num, len, flag));
}

int ft_print_number_type(s_arg s_arg, va_list *arg_ptr)
{
	int num;
	int len;
	char *str;
	char c;

	c = ' ';
	num = va_arg(*arg_ptr, int);
	str = ft_itoa(num);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (s_arg.precision != -1 && s_arg.precision < len)
		len = s_arg.precision;
	if (s_arg.flag & FLG_NULL)
		c = '0';
	if (s_arg.width > len)
	{
		if (!(s_arg.flag & FLG_MINUS))
		{
			len = s_arg.width - len;
			while (len--)
				write(1, &c, 1);
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
				write(1, &c, 1);
		}
		return (s_arg.width);
	}
	len = -1;
	while (str[++len])
	{
		if (s_arg.precision == len)
			break ;
		write(1, &(str[len]), 1);
	}
	free(str);
	return (len);
}
