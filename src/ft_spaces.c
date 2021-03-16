/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:11:03 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/16 13:41:50 by antonmar         ###   ########.fr       */
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
	if ((cut_num == 0 || stats.type != 'c')
		&& find_this_flag(stats.text, '.'))
		nowrite = 'T';
	while (num_spaces > 0)
	{
		if (find_this_flag(stats.text, '0') && nowrite != 'T')
			c = '0';
		ft_putchar(c);
		num_char++;
		num_spaces--;
	}
	while (num_spaces < 0)
	{
		ft_putchar(c);
		num_char++;
		num_spaces++;
	}
	return (num_char);
}
