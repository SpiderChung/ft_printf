/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:47:35 by schung            #+#    #+#             */
/*   Updated: 2021/10/27 21:51:11 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// flags to be handle with 0-. 

int	ft_parser_type(t_print *p, int start)
{
	int	rez;

	rez = 0;
	if (start == 'd' || start == 'i')
		rez += ft_print_i_d(p);
	if (start == 'u')
		rez += ft_print_u(p);
	if (start == 'c')
		rez += ft_print_char(p);
	if (start == 's')
		rez += ft_print_str(p);
	if (start == 'x' || start == 'X')
		rez += ft_print_hex(p, start);
	if (start == 'p')
		rez += ft_print_p(p);
	if (start == '%')
		rez += write(1, "%", 1);
	return (rez);
}

int	ft_parser_flags(t_print *p, const char *src, int start)
{
	int	rez;

	rez = 0;
	while (!(ft_strchr(SPECS, (char)src[start])))
	{
		if ((int)src[start++] == '.')
			p->point = 1;
		if ((int)src[start] == '-')
			p->dash = 1;
		start++;
	}
	rez += ft_parser_type(p, src[start]);
	return (rez);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	t_print	*tab;
	int		rez;

	rez = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_bzero(tab, sizeof(t_print));
	va_start(tab->args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			rez += write(1, &(format[i]), 1);
		else
			rez += ft_parser_flags(tab, format, ++i);
		i++;
	}
	ft_bzero(tab, sizeof(t_print));
	va_end(tab->args);
	free(tab);
	return (rez);
}
/*
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
	printf(" %p %p ", INT_MIN, INT_MAX);
	//printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	//printf(" %p %p ", 0, 0);
	ft_printf("\n");
	//ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	//ft_printf(" %p %p ", INT_MIN, INT_MAX);
	//ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	//ft_printf(" %p %p ", 0, 0);
}
*/
