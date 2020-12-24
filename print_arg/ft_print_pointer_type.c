/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:51:25 by apending          #+#    #+#             */
/*   Updated: 2020/12/24 21:43:06 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	*ft_memmove(void *dest, const void *source, size_t count)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = -1;
	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)source;
	if (dest == source)
		return (dest);
	if (dest > source)
		while (count--)
			p1[count] = p2[count];
	else
		while (++i != count)
			p1[i] = p2[i];
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	size_t	len1;
	size_t	len2;
	char	*res;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	size = len1 + len2 + 1;
	if (!(res = malloc(size * sizeof(char))))
		return (0);
	if (s1)
		ft_memmove((void *)res, (const void *)s1, len1);
	ft_memmove((void *)(res + len1), (const void *)s2, len2);
	*(res + size - 1) = 0;
	if (s2)
		free(s2);
	return (res);
}

char	*ft_getres_hex(char *res, unsigned long long num, int len)
{
	int hex;

	hex = 0;
	if (!num)
		res[0] = '0';
	else
	{
		while (len)
		{
			hex = num % 16;
			if (hex < 10)
				res[--len] = hex + '0';
			else
				res[--len] = hex - 10 + 'a';
			num /= 16;
		}
	}
	return (res);
}

char	*ft_itoa_hex(unsigned long long n)
{
	char			*res;
	int				len;

	len = ft_numlen(n);
	if (!n)
		len = 1;
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (0);
	res[len] = '\0';
	return (ft_getres_hex(res, n, len));
}

int ft_print_pointer_type(s_arg s_arg, va_list *arg_ptr)
{
	int len;
	int print_c;
	int flag_print;
	char *str;
	unsigned long num;

	num = (unsigned long)(va_arg(*arg_ptr, void*));
	print_c = 0;
	str = ft_itoa_hex(num);
	len = -1;
	flag_print = 0;
	write(1, "0x", 2);
	while (str[++len])
	{
		if (str[len] != '0')
			flag_print = 1;
		else if (!flag_print && num)
			continue ;
		write(1, &(str[len]), 1);
		print_c++;
	}
	free(str);
	return (print_c);
}
