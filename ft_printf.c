/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apending <apending@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:45:08 by apending          #+#    #+#             */
/*   Updated: 2020/12/17 20:25:23 by apending         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	int				i;
	int				print_res;
	int				print_check_val;
	va_list			arg_ptr;

	if (!format)
		return (0);
	va_start(arg_ptr, format);
	print_res = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if ((print_check_val =
				ft_printf_parser(format, &i, &arg_ptr)) == -1)
				return (-1);
			if (print_check_val != -2)
			{
				print_res += print_check_val;
				continue ;
			}

		}
		write(1, &(format[i]), 1);
		print_res++;
	}
	va_end(arg_ptr);
	return (print_res);
}

// int main(void)
// {
// 	//char format[] = "\nft_printf\n\nPercent - %%\nChar - start:%c:end\nString NULL - start:%s:end\nString - start:%s:end\nNumber 10 - start:%4.4d:end\n\n";
// 	char formatStr[] = "\nft_printf\n\nString my - start:%-10.5s:end";
// 	int res = 0;

// 	res = ft_printf(formatStr, "est");
// 	res = printf("\nString expend - start:%-10.5s:end\n\n", "est");
// 	// res = printf("\n%s", NULL);
// 	// printf("\nResult norm:%d\n\n", res);
// 	return (0);
// }
