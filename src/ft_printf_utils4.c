/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:42:47 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/15 18:01:56 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

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

void			ft_putun(char *str, unsigned int n)
{
	if (n > 9)
	{
		ft_putun(str, n / 10);
		n = n % 10;
	}
	ft_strfiller(str, n + 48);
}
