#include "ft_printf.h"

void	ft_bzero(void *src, size_t len)
{
	char	*a;
	size_t	i;

	i = 0;
	a = src;
	while (len - i > 0)
	{
		a[i] = 0;
		i++;
	}
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	*ft_strchr(const char *s, char c)
{
	int		i;
	char	*r;

	i = 0;
	r = (char *)s;
	while (r[i] != (char)c)
	{
		if (r[i] == '\0')
			return (0);
		i++;
	}
	return (r + i);
}

int	ft_putnbr_throwaway(int n, int *rez)
{
	if (n == -2147483648)
		*rez += write(1, "-2147483648", 11);
	else
		*rez += write(1, "0", 1);
	return (*rez);
}

int	ft_putnbr(int n)
{
	char	dst[20];
	int		i;
	int 	rez;

	i = 0;
	rez = 0;
	if ((n == -2147483648) || (n == 0))
		return (ft_putnbr_throwaway(n, &rez));
	if (n < 0)
	{
		rez += write(1, "-", 1);
		n = n * (-1);
	}
	while (n)
	{
		dst[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
		rez += write(1, &dst[i--], 1);
	return (rez);
}