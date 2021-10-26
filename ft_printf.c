/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:55:41 by schung            #+#    #+#             */
/*   Updated: 2021/10/22 20:55:44 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_integer(t_print *tab)
{
	int n;

	n = va_arg(tab->args, int);
	ft_putnbr(n);
}

int	ft_print_char(t_print *tab)
{
	char c;
	int rez;

	c = va_arg(tab->args, char);
	rez += write(1, &c, 1);
	return (rez);
}

void	ft_parse_flags(char *src)
{
	
}

void	ft_parser_type(t_print *p, const char *src, int start)
{
	while (!(ft_strchr("idcsupxX%", (char)src[start])))
	{
		if ((int)src[start] == '.')
		{
			p->point = 1;
			start++;
		}
		if ((int)src[start] == '-')
		{
			p->dash = 1;
			start++;
		}
		start++;
	}
	if ((int)src[start] == 'd' || (int)src[start] == 'i')
		ft_print_integer(p);
	if ((int)src[start] == 'c')
		ft_print_char(p);

}

int ft_printf(const char *format, ...)
{
	char *h;
	int i;
	t_print *tab;
	int	rez;

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
			ft_parser_type(tab, format, ++i);
		i++;
	}
	va_end(tab->args);
	return (0);
}

int main()
{
	ft_printf("First is d = %d \nSecond is i = %i \nThird is c = %c\n", -2147483647, 87978, 'k', "gay", 2, 3);
	//printf( "%0*x", 8, 15 );
	//printf("First is d = %d \n Second is c = \n", -2147483647, "hello", "gay", 2, 3);
}