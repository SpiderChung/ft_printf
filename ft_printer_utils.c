/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:51:32 by schung            #+#    #+#             */
/*   Updated: 2021/10/27 21:56:14 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_p(t_print *tab)
{
	int					rez;
	long unsigned int	l;

	l = va_arg(tab->args, long unsigned int);
	rez = 0;
	rez += write(1, "0x", 2);
	rez += ft_itoa_base(l, 16, 1);
	return (rez);
}

int	ft_print_i_d(t_print *tab)
{
	int	n;
	int	rez;

	rez = 0;
	n = va_arg(tab->args, int);
	rez += ft_putnbr(n);
	return (rez);
}

int	ft_print_u(t_print *tab)
{
	unsigned int	n;
	int				rez;

	rez = 0;
	n = va_arg(tab->args, unsigned int);
	rez += ft_itoa_base(n, 10, 1);
	return (rez);
}

int	ft_print_char(t_print *tab)
{
	char	c;
	int		rez;

	rez = 0;
	c = va_arg(tab->args, int);
	rez += write(1, &c, 1);
	return (rez);
}

int	ft_print_str(t_print *tab)
{
	char	*s;
	int		rez;
	int		i;

	s = va_arg(tab->args, char *);
	if (s == 0)
	{
		return (write(1, "(null)", 6));
	}
	rez = 0;
	i = 0;
	if (s)
	{
		while (s[i])
		{
			rez += write(1, s + i, 1);
			i++;
		}
	}
	return (rez);
}

int	ft_print_hex(t_print *tab, int reg)
{
	int				rez;
	unsigned int	h;

	h = va_arg(tab->args, unsigned int);
	rez = 0;
	if (reg == 'x')
		rez += ft_itoa_base(h, 16, 1);
	else
		rez += ft_itoa_base(h, 16, 0);
	return (rez);
}

int	ft_itoa_base(unsigned int number, int id, int flag)
{
	char	dst[20];
	int		i;
	int		rez;

	i = 0;
	rez = 0;
	if (number == 0)
		return (write(1, "0", 1));
	while (number)
	{
		dst[i] = number % id + '0';
		if (dst[i] > '9')
		{
			dst[i] += 39;
			if (flag == 0)
				dst[i] = ft_toupper(dst[i]);
		}
		number = number / id;
		i++;
	}
	i--;
	while (i >= 0)
		rez += write(1, &dst[i--], 1);
	return (rez);
}
