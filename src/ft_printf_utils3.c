/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:40:22 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/18 19:40:58 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

long	find_simb(const char *str, int i)
{
	long	simb;

	simb = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			simb = -1;
	}
	return (simb);
}

int	ft_atoi(const char *str)
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

void	ft_putn(char *str, int n)
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

int	ft_sizeofnum(int n)
{
	int	size;

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

char	*ft_itoa(int n)
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
		return (str);
	}
	ft_putn(str, n);
	return (str);
}
