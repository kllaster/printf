#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "printf.h"
//#include "libftprintf.h"

void error(int c1, int c2)
{
	if (c1 != c2)
		printf("__________________!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!____________________\nprintf_%d | ft_printf_%d\n\n", c1, c2);
}

int main()
{
	char str[100];
	char str1[100];
	int c1;
	int c2;

	strcpy(str, "hello");
	strcpy(str1, "a");

//	printf("\n\n\n__________________________________________________________________________________\n");
//	printf("\nTEST_STRINGS\n\n");
//

//	c2 = ft_printf("*|%.0s|\n", "Hello");
//	c1 = printf(">|%.0s|\n", "Hello");
//	error(c1, c2);
//
//	c2 = ft_printf("*|%3.s|\n", NULL);
//	c1 = printf(">|%3.s|\n", NULL);
//	error(c1, c2);
//
//	c2 = ft_printf("**|%10.s|\n", NULL);
//	c1 = printf("88|%10.0s|\n", NULL);
//	error(c1, c2);
//
//	c2 = ft_printf("**|%-3.s|\n", "Hello");
//	c1 = printf("92|%-3.s|\n", "Hello");
//	error(c1, c2);
//
//	c2 = ft_printf("**|%-3.s|\n", NULL);
//	c1 = printf("94|%-3.s|\n", NULL);
//	error(c1, c2);
//
//	c2 = ft_printf("***|%-.00s|\n", "Hello");
//	c1 = printf("121|%-.00s|\n", "Hello");
//	error(c1, c2);
//
//	c2 = ft_printf("***|%-09s|\n", "Hello");
//	c1 = printf("132|%-09s|\n", "Hello");
//	error(c1, c2);
//
//	c2 = ft_printf("***|%0-9s|\n", "Hello");
//	c1 = printf("132|%0-9s|\n", "Hello");
//	error(c1, c2);

//	c2 = ft_printf("***|%c|\n", '\0');
//	c1 = printf("457|%c|\n", '\0');
//	error(c1, c2);
//
//	c2 = ft_printf("***|%5c|\n", '\0');
//	c1 = printf("458|%5c|\n", '\0');
//	error(c1, c2);
//
//	c2 = ft_printf("***|%-5c|\n", '\0');
//	c1 = printf("459|%-5c|\n", '\0');
//	error(c1, c2);
//
//	c2 = ft_printf("***|%c|\n", -0);
//	c1 = printf("645|%c|\n", -0);
//	error(c1, c2);
//
//	c2 = ft_printf("***|%c|\n", 0);
//	c1 = printf("646|%c|\n", 0);
//	error(c1, c2);
//
//	c2 = ft_printf("***|%.*s|\n", 0, "hello");
//	c1 = printf("730|%.*s|\n", 0, "hello");
//	error(c1, c2);
//
//	c2 = ft_printf("***|%*i|\n", -4, 94827);
//	c1 = printf("741|%*i|\n", -4, 94827);
//	error(c1, c2);

		printf("\nTest with NULL:\n");
	printf("\nTest with NULL:\n");
	c1 = printf("%s|%-s|%10s|%.5s|%.10s|%-10s|%-.5s|%-.10s|%10.5s|%7.10s|%-10.5s|%-7.10s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	c2 = ft_printf("%s|%-s|%10s|%.5s|%.10s|%-10s|%-.5s|%-.10s|%10.5s|%7.10s|%-10.5s|%-7.10s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	error(c1, c2);

	printf("\n\nTest with \"\":\n");
	c1 = printf(">|%s|%-s|%5s|%-5s|%2.4s|\n", "", "", "", "", "");
	c2 = ft_printf("*|%s|%-s|%5s|%-5s|%2.4s|\n", "", "", "", "", "");
	error(c1, c2);

	c2 = ft_printf("*|{%.*s}\n", -5, "42");
	c1 = printf(">|{%.*s}\n", -5, "42");
	error(c1, c2);

	printf("\n\nTests with *:\n");

	c2 = ft_printf("{%%.*s}|* = -5|                           *|{%.*s}\n", -5, "42");
	c1 = printf("{%%.*s}|* = -5|                            |{%.*s}\n", -5, "42");
	error(c1, c2);

	c2 = ft_printf("{%%*s}|* = -5|                            *|{%*s}\n", -5, "42");
	c1 = printf("{%%*s}|* = -5|                             |{%*s}\n", -5, "42");
	error(c1, c2);
	c2 = ft_printf("{%%3.*s}|* = -5|                          *|{%3.*s}\n", -5, "42");
	c1 = printf("{%%3.*s}|* = -5|                           |{%3.*s}\n", -5, "42");
	error(c1, c2);
	c2 = ft_printf("{%%20.*s}|* = -5|                         *|{%20.*s}\n", -5, "42");
	c1 = printf("{%%20.*s}|* = -5|                          |{%20.*s}\n", -5, "42");
	error(c1, c2);
	c2 = ft_printf("{%%-3.*s}|* = -5|                         *|{%-3.*s}\n", -5, "42");
	c1 = printf("{%%-3.*s}|* = -5|                          |{%-3.*s}\n", -5, "42");
	error(c1, c2);
	c2 = ft_printf("|%%*.*s|%%10.15s|* = 10, 15|               *|%*.*s|%10.15s|\n", 10, 15, str, str1);
	c1 = printf("|%%*.*s|%%10.15s|* = 10, 15|                |%*.*s|%10.15s|\n", 10, 15, str, str1);
	error(c1, c2);
	c2 = ft_printf("|%%-*.*s|%%-10.15s|* = 10, 15|             *|%-*.*s|%-10.15s|\n", 10, 15, str, str1);
	c1 = printf("|%%-*.*s|%%-10.15s|* = 10, 15|              |%-*.*s|%-10.15s|\n", 10, 15, str, str1);
	error(c1, c2);

	printf("\n\nNormal tests without warnings:\n");

	c2 = ft_printf("|%%s|%%s|                                  *|%s|%s|\n", str, str1);
	c1 = printf("|%%s|%%s|                                   |%s|%s|\n", str, str1);
	error(c1, c2);
	c2 = ft_printf("|%%-s|%%s|                                 *|%-s|%s|\n", str, str1);
	c1 = printf("|%%-s|%%s|                                  |%-s|%s|\n", str, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%s|%%1s|%%2s|%%5s|%%10s|                    *|%s|%1s|%2s|%5s|%10s|\n", str, str, str, str, str);
	c1 = printf("|%%s|%%1s|%%2s|%%5s|%%10s|                     |%s|%1s|%2s|%5s|%10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%s|%%1s|%%2s|%%5s|%%10s|                    *|%s|%1s|%2s|%5s|%10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%s|%%1s|%%2s|%%5s|%%10s|                     |%s|%1s|%2s|%5s|%10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-s|%%-1s|%%-2s|%%-5s|%%-10s|               *|%-s|%-1s|%-2s|%-5s|%-10s|\n", str, str, str, str, str);
	c1 = printf("|%%-s|%%-1s|%%-2s|%%-5s|%%-10s|                |%-s|%-1s|%-2s|%-5s|%-10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-s|%%-1s|%%-2s|%%-5s|%%-10s|               *|%-s|%-1s|%-2s|%-5s|%-10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-s|%%-1s|%%-2s|%%-5s|%%-10s|                |%-s|%-1s|%-2s|%-5s|%-10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");

	c2 = ft_printf("*|%.s|\n", "Hello");
	c1 = printf(">|%.s|\n", "Hello");
	error(c1, c2);

	c2 = ft_printf("|%%.s|%%.1s|%%.2s|%%.5s|%%.10s|               *|%.s|%.1s|%.2s|%.5s|%.10s|\n", str, str, str, str, str);
	c1 = printf("|%%.s|%%.1s|%%.2s|%%.5s|%%.10s|                |%.s|%.1s|%.2s|%.5s|%.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%.s|%%.1s|%%.2s|%%.5s|%%.10s|               *|%.s|%.1s|%.2s|%.5s|%.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%.s|%%.1s|%%.2s|%%.5s|%%.10s|                |%.s|%.1s|%.2s|%.5s|%.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%--s|%%--1s|%%--2s|%%--5s|%%--10s|          *|%--s|%--1s|%--2s|%--5s|%--10s|\n", str, str, str, str, str);
	c1 = printf("|%%--s|%%--1s|%%--2s|%%--5s|%%--10s|           |%--s|%--1s|%--2s|%--5s|%--10s|\n", str, str, str, str, str);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-.s|%%-.1s|%%-.2s|%%-.5s|%%-.10s|          *|%-.s|%-.1s|%-.2s|%-.5s|%-.10s|\n", str, str, str, str, str);
	c1 = printf("|%%-.s|%%-.1s|%%-.2s|%%-.5s|%%-.10s|           |%-.s|%-.1s|%-.2s|%-.5s|%-.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-.s|%%-.1s|%%-.2s|%%-.5s|%%-.10s|          *|%-.s|%-.1s|%-.2s|%-.5s|%-.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-.s|%%-.1s|%%-.2s|%%-.5s|%%-.10s|           |%-.s|%-.1s|%-.2s|%-.5s|%-.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%.s|%%1.s|%%2.s|%%5.s|%%10.s|               *|%.s|%1.s|%2.s|%5.s|%10.s|\n", str, str, str, str, str);
	c1 = printf("|%%.s|%%1.s|%%2.s|%%5.s|%%10.s|                |%.s|%1.s|%2.s|%5.s|%10.s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%.s|%%1.s|%%2.s|%%5.s|%%10.s|               *|%.s|%1.s|%2.s|%5.s|%10.s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%.s|%%1.s|%%2.s|%%5.s|%%10.s|                |%.s|%1.s|%2.s|%5.s|%10.s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-.s|%%-1.s|%%-2.s|%%-5.s|%%-10.s|          *|%-.s|%-1.s|%-2.s|%-5.s|%-10.s|\n", str, str, str, str, str);
	c1 = printf("|%%-.s|%%-1.s|%%-2.s|%%-5.s|%%-10.s|           |%-.s|%-1.s|%-2.s|%-5.s|%-10.s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-.s|%%-1.s|%%-2.s|%%-5.s|%%-10.s|          *|%-.s|%-1.s|%-2.s|%-5.s|%-10.s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-.s|%%-1.s|%%-2.s|%%-5.s|%%-10.s|           |%-.s|%-1.s|%-2.s|%-5.s|%-10.s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%.0s|%%1.0s|%%2.0s|%%5.0s|%%10.0s|          *|%.0s|%1.0s|%2.0s|%5.0s|%10.0s|\n", str, str, str, str, str);
	c1 = printf("|%%.0s|%%1.0s|%%2.0s|%%5.0s|%%10.0s|           |%.0s|%1.0s|%2.0s|%5.0s|%10.0s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%.0s|%%1.0s|%%2.0s|%%5.0s|%%10.0s|          *|%.0s|%1.0s|%2.0s|%5.0s|%10.0s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%.0s|%%1.0s|%%2.0s|%%5.0s|%%10.0s|           |%.0s|%1.0s|%2.0s|%5.0s|%10.0s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-.0s|%%-1.0s|%%-2.0s|%%-5.0s|%%-10.0s|     *|%-.0s|%-1.0s|%-2.0s|%-5.0s|%-10.0s|\n", str, str, str, str, str);
	c1 = printf("|%%-.0s|%%-1.0s|%%-2.0s|%%-5.0s|%%-10.0s|      |%-.0s|%-1.0s|%-2.0s|%-5.0s|%-10.0s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-.0s|%%-1.0s|%%-2.0s|%%-5.0s|%%-10.0s|     *|%-.0s|%-1.0s|%-2.0s|%-5.0s|%-10.0s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-.0s|%%-1.0s|%%-2.0s|%%-5.0s|%%-10.0s|      |%-.0s|%-1.0s|%-2.0s|%-5.0s|%-10.0s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%1.s|%%1.1s|%%1.2s|%%1.5s|%%1.10s|          *|%1.s|%1.1s|%1.2s|%1.5s|%1.10s|\n", str, str, str, str, str);
	c1 = printf("|%%1.s|%%1.1s|%%1.2s|%%1.5s|%%1.10s|           |%1.s|%1.1s|%1.2s|%1.5s|%1.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%1.s|%%1.1s|%%1.2s|%%1.5s|%%1.10s|          *|%1.s|%1.1s|%1.2s|%1.5s|%1.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%1.s|%%1.1s|%%1.2s|%%1.5s|%%1.10s|           |%1.s|%1.1s|%1.2s|%1.5s|%1.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-1.s|%%-1.1s|%%-1.2s|%%-1.5s|%%-1.10s|     *|%-1.s|%-1.1s|%-1.2s|%-1.5s|%-1.10s|\n", str, str, str, str, str);
	c1 = printf("|%%-1.s|%%-1.1s|%%-1.2s|%%-1.5s|%%-1.10s|      |%-1.s|%-1.1s|%-1.2s|%-1.5s|%-1.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-1.s|%%-1.1s|%%-1.2s|%%-1.5s|%%-1.10s|     *|%-1.s|%-1.1s|%-1.2s|%-1.5s|%-1.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-1.s|%%-1.1s|%%-1.2s|%%-1.5s|%%-1.10s|      |%-1.s|%-1.1s|%-1.2s|%-1.5s|%-1.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%5.s|%%5.1s|%%5.2s|%%5.5s|%%5.10s|          *|%5.s|%5.1s|%5.2s|%5.5s|%5.10s|\n", str, str, str, str, str);
	c1 = printf("|%%5.s|%%5.1s|%%5.2s|%%5.5s|%%5.10s|           |%5.s|%5.1s|%5.2s|%5.5s|%5.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%5.s|%%5.1s|%%5.2s|%%5.5s|%%5.10s|          *|%5.s|%5.1s|%5.2s|%5.5s|%5.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%5.s|%%5.1s|%%5.2s|%%5.5s|%%5.10s|           |%5.s|%5.1s|%5.2s|%5.5s|%5.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-5.s|%%-5.1s|%%-5.2s|%%-5.5s|%%-5.10s|     *|%-5.s|%-5.1s|%-5.2s|%-5.5s|%-5.10s|\n", str, str, str, str, str);
	c1 = printf("|%%-5.s|%%-5.1s|%%-5.2s|%%-5.5s|%%-5.10s|      |%-5.s|%-5.1s|%-5.2s|%-5.5s|%-5.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-5.s|%%-5.1s|%%-5.2s|%%-5.5s|%%-5.10s|     *|%-5.s|%-5.1s|%-5.2s|%-5.5s|%-5.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-5.s|%%-5.1s|%%-5.2s|%%-5.5s|%%-5.10s|      |%-5.s|%-5.1s|%-5.2s|%-5.5s|%-5.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%10.s|%%10.1s|%%10.2s|%%10.5s|%%10.10s|     *|%10.s|%10.1s|%10.2s|%10.5s|%10.10s|\n", str, str, str, str, str);
	c1 = printf("|%%10.s|%%10.1s|%%10.2s|%%10.5s|%%10.10s|      |%10.s|%10.1s|%10.2s|%10.5s|%10.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%10.s|%%10.1s|%%10.2s|%%10.5s|%%10.10s|     *|%10.s|%10.1s|%10.2s|%10.5s|%10.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%10.s|%%10.1s|%%10.2s|%%10.5s|%%10.10s|      |%10.s|%10.1s|%10.2s|%10.5s|%10.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-10.s|%%-10.1s|%%-10.2s|%%-10.5s|%%-10.10s|*|%-10.s|%-10.1s|%-10.2s|%-10.5s|%-10.10s|\n", str, str, str, str, str);
	c1 = printf("|%%-10.s|%%-10.1s|%%-10.2s|%%-10.5s|%%-10.10s| |%-10.s|%-10.1s|%-10.2s|%-10.5s|%-10.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-10.s|%%-10.1s|%%-10.2s|%%-10.5s|%%-10.10s|*|%-10.s|%-10.1s|%-10.2s|%-10.5s|%-10.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-10.s|%%-10.1s|%%-10.2s|%%-10.5s|%%-10.10s| |%-10.s|%-10.1s|%-10.2s|%-10.5s|%-10.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

//	printf("\n\n-------------------------------\n|  Undefined behavior tests:  |\n-------------------------------\n\n");
//
//	printf("Test with 0:\n");
//	c1 = printf("%s|%-s|%10s|%.5s|%.10s|%-10s|%-.5s|%-.10s|%10.5s|%7.10s|%-10.5s|%-7.10s|\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
//	c2 = ft_printf("%s|%-s|%10s|%.5s|%.10s|%-10s|%-.5s|%-.10s|%10.5s|%7.10s|%-10.5s|%-7.10s|\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
//	error(c1, c2);
//
//	printf("\n");
//	c2 = ft_printf("|%%5-s|%%5-1s|%%5-2s|%%5-5s|%%5-10s|          *|%5-s|%5-1s|%5-2s|%5-5s|%5-10s|\n", str, str, str, str, str);
//	c1 = printf("|%%5-s|%%5-1s|%%5-2s|%%5-5s|%%5-10s|           |%5-s|%5-1s|%5-2s|%5-5s|%5-10s|\n", str, str, str, str, str);
//	error(c1, c2);
//
//	printf("\n");
//	c2 = ft_printf("|%%-5-s|%%-5-1s|%%-5-2s|%%-5-5s|%%-5-10s|     *|%-5-s|%-5-1s|%-5-2s|%-5-5s|%-5-10s|\n", str, str, str, str, str);
//	c1 = printf("|%%-5-s|%%-5-1s|%%-5-2s|%%-5-5s|%%-5-10s|      |%-5-s|%-5-1s|%-5-2s|%-5-5s|%-5-10s|\n", str, str, str, str, str);
//	error(c1, c2);
//
//	printf("\n");
//	c2 = ft_printf("|%%-0-s|%%-0-1s|%%-0-2s|%%-0-5s|%%-0-10s|     *|%-0-s|%-0-1s|%-0-2s|%-0-5s|%-0-10s|\n", str, str, str, str, str);
//	c1 = printf("|%%-0-s|%%-0-1s|%%-0-2s|%%-0-5s|%%-0-10s|      |%-0-s|%-0-1s|%-0-2s|%-0-5s|%-0-10s|\n", str, str, str, str, str);
//	error(c1, c2);
//
//	printf("\n");
//	c2 = ft_printf("|%%.-s|%%.-1s|%%.-2s|%%.-5s|%%.-10s|          *|%.-s|%.-1s|%.-2s|%.-5s|%.-10s|\n", str, str, str, str, str);
//	c1 = printf("|%%.-s|%%.-1s|%%.-2s|%%.-5s|%%.-10s|           |%.-s|%.-1s|%.-2s|%.-5s|%.-10s|\n", str, str, str, str, str);
//	error(c1, c2);
//
//	printf("\n");
//	c2 = ft_printf("|%%0s|%%09s|%%00s|%%0.s|%%0.0s|%%0.7s|         *|%0s|%09s|%00s|%0.s|%0.0s|%0.7s|\n", str, str, str, str, str, str);
//	c1 = printf("|%%0s|%%09s|%%00s|%%0.s|%%0.0s|%%0.7s|          |%0s|%09s|%00s|%0.s|%0.0s|%0.7s|\n", str, str, str, str, str, str);
//	error(c1, c2);
//	c2 = ft_printf("|%%-0s|%%-05s|%%-00s|%%-0.s|%%-0.0s|%%-0.7s|   *|%-0s|%-05s|%-00s|%-0.s|%-0.0s|%-0.7s|\n", str, str, str, str, str, str);
//	c1 = printf("|%%-0s|%%-05s|%%-00s|%%-0.s|%%-0.0s|%%-0.7s|    |%-0s|%-05s|%-00s|%-0.s|%-0.0s|%-0.7s|\n", str, str, str, str, str, str);
//	error(c1, c2);
//	c2 = ft_printf("|%%0s|%%05s|%%00s|%%0.s|%%0.0s|%%0.7s|         *|%0s|%05s|%00s|%0.s|%0.0s|%0.7s|\n", str1, str1, str1, str1, str1, str1);
//	c1 = printf("|%%0s|%%05s|%%00s|%%0.s|%%0.0s|%%0.7s|          |%0s|%05s|%00s|%0.s|%0.0s|%0.7s|\n", str1, str1, str1, str1, str1, str1);
//	error(c1, c2);
//	c2 = ft_printf("|%%-0s|%%-05s|%%-00s|%%-0.s|%%-0.0s|%%-0.7s|   *|%-0s|%-05s|%-00s|%-0.s|%-0.0s|%-0.7s|\n", str1, str1, str1, str1, str1, str1);
//	c1 = printf("|%%-0s|%%-05s|%%-00s|%%-0.s|%%-0.0s|%%-0.7s|    |%-0s|%-05s|%-00s|%-0.s|%-0.0s|%-0.7s|\n", str1, str1, str1, str1, str1, str1);
//	error(c1, c2);

}
