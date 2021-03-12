/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:56:20 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/12 17:07:21 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	free_all(char *to_free)
{
	to_free = NULL;
	free(to_free);
}

void			*ft_calloc(size_t nitems, size_t size)
{
	void	*pointer;
	int		i;

	i = 0;
	pointer = malloc(nitems * size);
	if (pointer == NULL)
		return (NULL);
	while (i < (int)nitems * (int)size)
	{
		((char *)pointer)[i] = '\0';
		i++;
	}
	return (pointer);
}

char			*ft_strdup(const char *string)
{
	unsigned int	i;
	void			*tams;

	i = 0;
	tams = malloc(ft_strlen(string) + 1);
	if (tams != NULL)
	{
		while (i < ft_strlen(string) + 1)
		{
			((char *)tams)[i] = string[i];
			i++;
		}
	}
	return (tams);
}

long			find_simb(const char *str, int i)
{
	long simb;

	simb = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			simb = -1;
	}
	return (simb);
}

int				ft_atoi(const char *str)
{
	int		i;
	long	res;
	long	simb;

	res = 0;
	i = 0;
	simb = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	simb = find_simb(str, i);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res * simb > 2147483648)
			return (-1);
		else if (res * simb < -2147483648)
			return (0);
		res = str[i] - 48 + res * 10;
		i++;
	}
	res *= simb;
	return (res);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void			ft_strfiller(char *str, char c)
{
	int i;

	i = ft_strlen(str);
	str[i] = c;
	str[i + 1] = '\0';
}

int				ft_sizeofnum(int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n == 2147483647)
		return (10);
	if (n < 0)
	{
		size = 1;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

void			ft_putn(char *str, int n)
{
	if (n < 0)
	{
		ft_strfiller(str, '-');
		ft_putn(str, n * -1);
		return ;
	}
	if (n > 9)
	{
		ft_putn(str, n / 10);
		n = n % 10;
	}
	ft_strfiller(str, n + 48);
}

char			*ft_itoa(int n)
{
	char	*str;

	str = ft_calloc(ft_sizeofnum(n) + 1, 1);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		ft_putn(str, (n % 1000000000) * -1);
		ft_strfiller(str, '\0');
		return (str);
	}
	ft_putn(str, n);
	ft_strfiller(str, '\0');
	return (str);
}

void			ft_putun(char *str, unsigned int n)
{
	if (n > 9)
	{
		ft_putun(str, n / 10);
		n = n % 10;
	}
	ft_strfiller(str, n + 48);
}

int				ft_sizeofunum(unsigned	int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	if (n == 4294967295)
		return (10);
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_unsigned_itoa(unsigned int n)
{
	char	*str;

	str = ft_calloc(ft_sizeofunum(n) + 1, 1);
	if (str == NULL)
		return (NULL);
	ft_putun(str, n);
	ft_strfiller(str, '\0');
	return (str);
}

char			ft_toupper(char c)
{
	if (c <= 122 && c >= 97)
		c = c - 32;
	return (c);
}

void			ft_strmayus(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

void			basenum(unsigned long num, char *base, char *str)
{
	if (num >= ft_strlen(base))
	{
		basenum(num / ft_strlen(base), base, str);
		ft_strfiller(str, (base[num % ft_strlen(base)]));
	}
	if (num <= ft_strlen(base))
		ft_strfiller(str, base[num]);
}

int				check_hexsize(unsigned long nbr)
{
	int					size;
	unsigned long		num;

	num = nbr;
	size = 0;
	while (num >= 16)
	{
		num = num / 16;
		size++;
	}
	return (size + 1);
}

char			*ft_tohex(unsigned long nbr)
{
	char		*base;
	char		*str;

	base = "0123456789abcdef";
	str = ft_calloc(check_hexsize(nbr) + 1, 1);
	basenum(nbr, base, str);
	return (str);
}
