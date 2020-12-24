/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:47:59 by apending          #+#    #+#             */
/*   Updated: 2020/12/24 20:20:27 by apending         ###   ########.fr       */
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

char	*ft_getres(char *res, unsigned int num, int len)
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
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				len;
	unsigned int	num;

	len = ft_numlen(n);
	if (!n)
	{
		len += 1;
		n *= -1;
	}
	num = (unsigned int)n;
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (0);
	res[len] = 0;
	return (ft_getres(res, num, len));
}

int ft_print_width(char c, int print_c, s_arg s_arg, int len)
{
	if (s_arg.width > s_arg.precision)
	{
		while ((s_arg.width - print_c) > len && (s_arg.width - print_c) > s_arg.precision)
		{
			write(1, &c, 1);
			print_c++;
		}
	}
	return (print_c);
}

int ft_print_number_type(s_arg s_arg, va_list *arg_ptr)
{
	int len;
	int num;
	int sign;
	int print_c;
	char *str;
	char c;

	c = ' ';
	sign = 0;
	print_c = 0;
	num = va_arg(*arg_ptr, int);
	if ((FLG_NULL & s_arg.flag) && s_arg.precision == -1)
		c = '0';
	if (num < 0)
	{
		sign = 1;
		num *= -1;
	}
	str = ft_itoa(num);
	len = ft_strlen(str);
 	if (sign == 1 || (FLG_PLUS & s_arg.flag))
		print_c++;
 	if (c == '0' && (sign == 1 || (FLG_PLUS & s_arg.flag)))
	{
		write(1, sign == 0 ? "+" : "-", 1);
		sign = -1;
	}
	if (!(FLG_MINUS & s_arg.flag))
		print_c = ft_print_width(c, print_c, s_arg, len);
	if (sign > 0 || (FLG_PLUS & s_arg.flag))
		write(1, sign == 0 ? "+" : "-", 1);
	while (s_arg.precision-- > len)
	{
		write(1, "0", 1);
		print_c++;
	}
	len = -1;
	if (str[0] != '0' || (s_arg.precision != -1 && str[0] == '0'))
	{
		while (str[++len])
		{
			write(1, &(str[len]), 1);
			print_c++;
		}
	}
	else if (s_arg.width > 0)
	{
		write(1, " ", 1);
		print_c++;
	}
	if (FLG_MINUS & s_arg.flag)
		print_c = ft_print_width(c, print_c - len, s_arg, len) + len;
	return (print_c);
}
// int ft_print_number_type(s_arg s_arg, va_list *arg_ptr)
// {
// 	int len;
// 	int num;
// 	int sign;
// 	int print_c;
// 	char *str;
// 	char c;

// 	c = ' ';
// 	sign = 0;
// 	print_c = 0;
// 	num = va_arg(*arg_ptr, int);
// 	if (FLG_NULL & s_arg.flag)
// 		c = '0';
// 	if (num < 0)
// 	{
// 		sign = 1;
// 		num *= -1;
// 	}
// 	str = ft_itoa(num);
// 	len = ft_strlen(str);
// 	if (sign || (FLG_MINUS & s_arg.flag)
// 		&& !((FLG_MINUS & s_arg.flag) && sign)
// 		&& str[0] != '0' && c != '0')
// 	{
// 		write(1, "-", 1);
// 		print_c++;
// 		sign = 0;
// 	}
// 	while (--(s_arg.width) > len)
// 	{
// 		write(1, &c, 1);
// 		print_c++;
// 	}
// 	if (sign && str[0] != '0')
// 	{
// 		write(1, "-", 1);
// 		print_c++;
// 	}
// 	len = -1;
// 	while (--(s_arg.precision) > len)
// 	{
// 		write(1, '0', 1);
// 		print_c++;
// 	}
// 	while (str[++len])
// 	{
// 		if (s_arg.precision == len)
// 			break ;
// 		write(1, &(str[len]), 1);
// 		print_c++;
// 	}
// 	return (print_c);
// }
