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

	printf("\n\n\n__________________________________________________________________________________\n");
	printf("\nTEST_WITHOUT_FLAGS\n\n");

	c1 = printf("|    %|\n");
	c2 = ft_printf("|%5%|\n");
	error(c1, c2);

	c1 = printf("|%%    |\n");
	c2 = ft_printf("|%-5%|\n");
	error(c1, c2);

	c1 = printf("|0000%|\n");
	c2 = ft_printf("|%05%|\n");
	error(c1, c2);

	c1 = printf("|%-05%|\n");
	c2 = ft_printf("|%-05%|\n");
	error(c1, c2);

	c1 = printf("|");
	printf("<--original\n");
	c2 = ft_printf("|%");
	printf("<--my\n");
	error(c1, c2);

	c1 = printf("|");
	printf("<--original\n");
	c2 = ft_printf("|%5");
	printf("<--my\n");
	error(c1, c2);

	c1 = printf("|");
	printf("<--original\n");
	c2 = ft_printf("|%05");
	printf("<--my\n");
	error(c1, c2);

	c1 = printf("|");
	printf("<--original\n");
	c2 = ft_printf("|%-05");
	printf("<--my\n");
	error(c1, c2);

	c1 = printf("|");
	printf("<--original\n");
	c2 = ft_printf("|%-5");
	printf("<--my\n");
	error(c1, c2);

	c1 = printf("|(nu|\n");
	c2 = ft_printf("|%.03s|\n", NULL);
	error(c1, c2);

	c1 = printf("|  (|\n");
	c2 = ft_printf("|%3.1s|\n", NULL);
	error(c1, c2);

	c1 = printf("|        (|\n");
	c2 = ft_printf("|%9.1s|\n", NULL);
	error(c1, c2);

	c1 = printf("|(  |\n");
	c2 = ft_printf("|%-3.1s|\n", NULL);
	error(c1, c2);

	c1 = printf("|(        |\n");
	c2 = ft_printf("|%-9.1s|\n", NULL);
	error(c1, c2);

	c1 = printf("|0000hello|\n");
	c2 = ft_printf("|%09s|\n", "hello");
	error(c1, c2);

	c1 = printf("|hello|\n");
	c2 = ft_printf("|%.*s|\n", -3, "hello");
	error(c1, c2);

	c1 = printf("|-54    |\n");
	c2 = ft_printf("|%0*i|\n", -7, -54);
	error(c1, c2);

	c1 = printf("|yolo   |\n");
	c2 = ft_printf("|%-*.*s|\n", -7, -3, "yolo");
	error(c1, c2);

	c1 = printf("|hello|\n");
	c2 = ft_printf("|%.*3s|\n", -3, "hello");
	error(c1, c2);

//	c1 = printf("%w|%-w|%10w|%.5w|%.10w|%-10w|%-.5w|%-.10w|%10.5w|%7.10w|%-10.5w|%-7.10w|\n");
//	c2 = ft_printf("%w|%-w|%10w|%.5w|%.10w|%-10w|%-.5w|%-.10w|%10.5w|%7.10w|%-10.5w|%-7.10w|\n");
//	error(c1, c2);
//
//	c1 = printf(">>>%.|%-.|%10.|%.5.|%.10.|%-10.|%-.5.|%-.10.|%10.5.|%7.10.|%-10.5.|%-7.10.|\n");
//	c2 = ft_printf("***%.|%-.|%10.|%.5.|%.10.|%-10.|%-.5.|%-.10.|%10.5.|%7.10.|%-10.5.|%-7.10.|\n");
//	error(c1, c2);
//
//	c1 = printf("%.w|%-.w|%10.w|%.5.w|%.10.w|%-10.w|%-.5.w|%-.10.w|%10.5.w|%7.10.w|%-10.5.w|%-7.10.w|\n");
//	c2 = ft_printf("%.w|%-.w|%10.w|%.5.w|%.10.w|%-10.w|%-.5.w|%-.10.w|%10.5.w|%7.10.w|%-10.5.w|%-7.10.w|\n");
//	error(c1, c2);
//
//	c1 = printf("%|%-|%10|%.5|%.10|%-10|%-.5|%-.10|%10.5|%7.10|%-10.5|%-7.10|\n");
//	c2 = ft_printf("%|%-|%10|%.5|%.10|%-10|%-.5|%-.10|%10.5|%7.10|%-10.5|%-7.10|\n");
//	error(c1, c2);

//	c1 = printf("не верно|%.5.c|%.10.c|%-10.c|%-.5.c|%-.10.c|%10.5.c|%7.10.c|%-10.5.c|%-7.10.c|\n", 0, 0, 0, 0, 0, 0, 0, 0, 0);

	c1 = printf(">>>| | |          | | |          |       |          |       |\n");
	c2 = ft_printf("***|%.5.c|%.10.c|%-10.c|%-.5.c|%-.10.c|%10.5.c|%7.10.c|%-10.5.c|%-7.10.c|\n", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	error(c1, c2);
}