#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int g;
	char *d;

	d = "asdasd";
	//g =	ft_printf("First is d = %d \nSecond is i = %i \nThird is c = %c\nFourth is s = %s\nFifth is s = %x\n %%\nSixth is s = %p\nSeventh is u = %u\n  ", -2147483647, 4294967295, 'k', "gay", 95, d, 4294967295);
	//printf("d = %li \n", 4294967295);
	//printf( "%0*x", 8, 15 );
	g = printf(" NULL %s NULL ", NULL);
	printf("g == %d", g);
	g = ft_printf(" NULL %s NULL ", NULL);
	printf("g2 == %d", g);
	//printf("First is d = %d \n Second is c = \n", -2147483647, "hello", "gay", 2, 3);


	//printf(" %p %p ", LONG_MIN, LONG_MAX);
	//printf(" %p %p ", INT_MIN, INT_MAX);
	//printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	//printf(" %p %p ", 0, 0);
	ft_printf("\n");

	printf("printf %x \n", 0);

	ft_printf("main %x \n", 0);
	//ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	//ft_printf(" %p %p ", INT_MIN, INT_MAX);
	//ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	//ft_printf(" %p %p ", 0, 0);
}