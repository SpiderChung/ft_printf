/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:45:15 by schung            #+#    #+#             */
/*   Updated: 2021/10/27 19:46:45 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define SPECS "idcsupxX%"

typedef struct s_print
{
	va_list	args;
	int		width;
	int		precision;
	int		point;
	int		dash;
	int		zero;
	int		length;
	int		sign;
	int		percent;
	int		space;
	int		is_zero;
}	t_print;	

int		ft_print_i_d(t_print *tab);
int		ft_print_char(t_print *tab);
int		ft_print_u(t_print *tab);
int		ft_print_p(t_print *tab);
int		ft_print_str(t_print *tab);
int		ft_print_hex(t_print *tab, int reg);
int		ft_itoa_base(unsigned int number, int id, int flag);
void	ft_bzero(void *src, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *s, char c);	
int		ft_putnbr(int n);
int		ft_printf(const char *format, ...);

#endif
