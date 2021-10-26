/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:56:44 by schung            #+#    #+#             */
/*   Updated: 2021/10/22 20:56:51 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_print
{
	va_list args;
	int width;
	int	precision;
	int point;
	int dash;
	int zero;
	int length;
	int sign;
	int percent;
	int space;
	int is_zero;
}	t_print;	

void	ft_bzero(void *src, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *s, char c);
void	ft_putnbr(int n);

#endif