/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:55:46 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/19 16:34:04 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"
#include <stdio.h>

char	*justchar(char c)
{
	char	*str;

	if (c)
	{
		str = calloc(2, 1);
		ft_strfiller(str, c);
	}
	else
	{
		str = calloc(2, 1);
		ft_strfiller(str, '\x00');
	}
	return (str);
}

char	*allchar(char *arg)
{
	char	*str;

	if (!arg)
		return (arg);
	str = ft_strdup(arg);
	return (str);
}

void	point_hex(int	cut, unsigned long arg, char *str)
{
	int	checksize;

	checksize = check_hexsize(arg);
	if (arg == '\0')
		cut++;
	while (cut > checksize)
	{
		ft_strfiller(str, '0');
		cut--;
	}
}

char	*allpointer(char *text, unsigned long arg)
{
	char	*str;
	char	*base;
	int		cut;

	str = NULL;
	if (find_type(text) == 'p')
	{
		cut = num_cut(text);
		base = "0123456789abcdef";
		str = ft_calloc(check_hexsize(arg) + 3, 1);
		ft_strfiller(str, '0');
		ft_strfiller(str, 'x');
		if (find_this_flag(text, '.'))
			point_hex(cut, arg, str);
		if (arg || !find_this_flag(text, '.') || find_this_flag(text, '*'))
			basenum(arg, base, str);
	}
	return (str);
}

char	*allint(char *text, int arg)
{
	char	*str;

	if (find_type(text) == 'd' || find_type(text) == 'i')
		str = ft_itoa(arg);
	if (find_type(text) == 'u')
		str = ft_unsigned_itoa((unsigned int)arg);
	if (find_type(text) == 'x'
		|| find_type(text) == 'X' || find_type(text) == 'p')
	{
		str = ft_tohex((unsigned int)arg);
		if (find_type(text) == 'X')
			ft_strmayus(str);
	}
	return (str);
}
