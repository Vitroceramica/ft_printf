/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:11:03 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/19 16:45:44 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"
#include <stdio.h>

int	num_spaces(char *text)
{
	char	*aux;
	char	prior;
	int		num;

	aux = text;
	num = 0;
	prior = 0;
	while ((find_flag(aux) != 0 && find_flag(aux) != '.')
		|| (*aux >= 48 && *aux <= 57))
	{
		if (*aux == 45)
			prior = 1;
		aux++;
	}
	aux--;
	while (*aux >= 48 && *aux <= 57 && *aux)
		aux--;
	aux++;
	num = num + ft_atoi(aux);
	if (prior == 1)
		num *= -1;
	return (num);
}

int	check_varspaces (char *text, int var_spaces)
{
	if (find_this_flag(text, '-'))
	{
		if (var_spaces > 0)
			var_spaces = var_spaces * -1;
	}
	return (var_spaces);
}

int	real_spaces(int num_spaces, int adjust)
{
	if (num_spaces >= 0)
	{
		num_spaces = num_spaces - adjust;
		if (num_spaces < 0)
			num_spaces = 0;
	}
	if (num_spaces < 0)
	{
		num_spaces = num_spaces + adjust;
		if (num_spaces > 0)
			num_spaces = 0;
	}
	return (num_spaces);
}

int	print_spaces(struct s_text_stats stats, int num_spaces, int cut_num)
{
	char	nowrite;
	int		num_char;
	char	c;

	nowrite = 'F';
	c = ' ';
	num_char = 0;
	if ((cut_num == 0 || stats.type != 'c') && find_this_flag(stats.text, '.'))
		nowrite = 'T';
	if (find_this_flag(stats.text, '0') && stats.num_s < 0
		&& (stats.type != 's' || stats.type != 'p'))
		nowrite = 'F';
	if (num_spaces < 0)
		nowrite = 'T';
	if (num_spaces < 0)
		num_spaces *= -1;
	while (num_spaces > 0)
	{
		if (find_this_flag(stats.text, '0') && nowrite != 'T')
			c = '0';
		ft_putchar(c);
		num_char++;
		num_spaces--;
	}
	return (num_char);
}

int	astpoint_flag(struct s_text_stats stats)
{
	if (find_this_flag(stats.text, '0') && stats.num_s < 0
		&& (stats.type != 's' && stats.type != 'p'))
	{
		if (ft_atoi(stats.arg) < 0 && stats.type != 'u')
		{
			ft_putchar('-');
			stats.arg++;
			stats.res++;
			stats.var_spaces = real_spaces(stats.var_spaces, 1);
		}
		stats.res += print_point(stats, stats.num_s, stats.var_spaces);
	}
	else
		stats.res += print_point(stats, stats.num_s, stats.var_spaces);
	return (stats.res);
}
