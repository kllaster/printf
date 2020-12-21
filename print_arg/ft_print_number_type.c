/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:47:59 by apending          #+#    #+#             */
/*   Updated: 2020/12/21 19:40:50 by apending         ###   ########.fr       */
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

char	*ft_itoa(int n)
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
	int i;
	int num;
	int sign;
	int print_c;
	char *str;

	print_c = 0;
	num = va_arg(*arg_ptr, int);
	if (num < 0)
	{
		sign = 1;
		num *= -1;
	}
	if (!(str = ft_itoa(num)))
		return (-1);
	i = ft_strlen(str);
	if (sign)
	{
		write(1, '-', 1);
		print_c++;
	}
	while (s_arg.width != 0 && (s_arg.width)-- > i)
	{
		write(1, '0', 1);
		print_c++;
	}
	i = -1;
	while (str[++i])
	{
		if (s_arg.precision == i)
			break ;
		write(1, &(str[i]), 1);
		print_c++;
	}
	return (print_c);
}
