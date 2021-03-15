/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:40:22 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/15 17:59:59 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

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
