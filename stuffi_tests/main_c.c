#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "printf.h"

void error(int c1, int c2)
{
	if (c1 != c2)
		printf("__________________!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!____________________\nprintf_%d | ft_printf_%d\n\n", c1, c2);
}

int main()
{
	int c1;
	int c2;

	printf("\n\n\n__________________________________________________________________________________\n");
	printf("\nTEST_%%\n\n");

	c1 = printf("|%%--|%5%--|%05%--|%-5%--|%-05%--|%.5%--|%-.5%--|%03.5%--|%3.5%--|%5.3%|\n");
	c2 = ft_printf("|%%--|%5%--|%05%--|%-5%--|%-05%--|%.5%--|%-.5%--|%03.5%--|%3.5%--|%5.3%|\n");
	error(c1, c2);

	printf("\n\n\n__________________________________________________________________________________\n");
	printf("\nTEST_CHARS\n");

	printf("\nTest with 0:\n");
	c1 = printf("|%c|%5c|%10c|%-5c|%-c|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("|%c|%5c|%10c|%-5c|%-c|\n", 0, 0, 0, 0, 0);
	error(c1, c2);

	printf("\nNormal tests without warnings:\n");
	c1 = printf("%c, %1c, %3c, %10c\n", 'a', 'a', 'a', 'a');
	c2 = ft_printf("%c, %1c, %3c, %10c\n", 'a', 'a', 'a', 'a');
	error(c1, c2);

	c1 = printf("%-c, %-1c, %-3c, %-10c\n", 'a', 'a', 'a', 'a');
	c2 = ft_printf("%-c, %-1c, %-3c, %-10c\n", 'a', 'a', 'a', 'a');
	error(c1, c2);

	c1 = printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	c2 = ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	error(c1, c2);

	printf("\n\n-------------------------------\n|  Undefined behavior tests:  |\n-------------------------------\n\n");

	printf("Test with NULL:\n");
	c1 = printf("|%c--|%5c--|%05c--|%-5c--|%-05c--|%.5c--|%-.5c--|%03.5c|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	c2 = ft_printf("|%c--|%5c--|%05c--|%-5c--|%-05c--|%.5c--|%-.5c--|%03.5c|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	error(c1, c2);
	printf("\n");

	printf("Test with 0:\n");
	c1 = printf("|%c--|%5c--|%05c--|%-5c--|%-05c--|%.5c--|%-.5c--|%03.5c--|%3.5c--|%-3.5c--|%0c|\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	c2 = ft_printf("|%c--|%5c--|%05c--|%-5c--|%-05c--|%.5c--|%-.5c--|%03.5c--|%3.5c--|%-3.5c--|%0c|\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	error(c1, c2);
	printf("\n");

	printf("Test with nothing:\n");
	c1 = printf("|%c--|%5c--|%05c--|%-5c--|%-05c--|%.5c--|%-.5c--|%03.5c--|%3.5c--|%-3.5c--|%0c|\n", 0);
	c2 = ft_printf("|%c--|%5c--|%05c--|%-5c--|%-05c--|%.5c--|%-.5c--|%03.5c--|%3.5c--|%-3.5c--|%0c|\n", 0);
	error(c1, c2);
	printf("\n");

	c1 = printf("%0c, %1.0c, %3.1c, %10.1c\n", 'a', 'a', 'a', 'a');
	c2 = ft_printf("%0c, %1.0c, %3.1c, %10.1c\n", 'a', 'a', 'a', 'a');
	error(c1, c2);

	c1 = printf("%0c, %01.0c, %03.1c, %010.1c\n", 'a', 'a', 'a', 'a');
	c2 = ft_printf("%00c, %01.0c, %03.1c, %010.1c\n", 'a', 'a', 'a', 'a');
	error(c1, c2);

	c1 = printf("%-0c, %-01c, %-03c, %-010c\n", 'a', 'a', 'a', 'a');
	c2 = ft_printf("%-0c, %-01c, %-03c, %-010c\n", 'a', 'a', 'a', 'a');
	error(c1, c2);
}
