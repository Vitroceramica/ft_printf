/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:42:47 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/17 13:14:45 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

void	*ft_calloc(size_t nitems, size_t size)
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

char	*ft_strdup(const char *string)
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

void	ft_putun(char *str, unsigned int n)
{
	if (n > 9)
	{
		ft_putun(str, n / 10);
		n = n % 10;
	}
	ft_strfiller(str, n + 48);
}

int	ft_sizeofunum(unsigned	int n)
{
	int	size;

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

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*str;

	str = ft_calloc(ft_sizeofunum(n) + 1, 1);
	if (str == NULL)
		return (NULL);
	ft_putun(str, n);
	return (str);
}
