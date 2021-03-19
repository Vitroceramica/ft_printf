/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:00:11 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/19 16:23:42 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"
#include <stdio.h>

int	num_cut(char *text)
{
	char	*aux;
	int		num;

	aux = text;
	num = 0;
	while ((find_flag(aux) != 0) || (*aux >= 48 && *aux <= 57))
		aux++;
	aux--;
	while (*aux >= 48 && *aux <= 57 && *aux)
		aux--;
	aux++;
	num = num + ft_atoi(aux);
	return (num);
}

int	print_diuxX(struct s_text_stats stats, int num_char, int cut_num)
{
	if (*stats.arg == '0')
		stats.arg = "\0";
	if (ft_atoi(stats.arg) < 0 && stats.type != 'u'
		&& (unsigned int)ft_atoi(stats.arg) != 2147483648)
	{
		ft_putchar('-');
		num_char++;
		stats.arg++;
	}
	cut_num = cut_num - ft_strlen(stats.arg);
	while (cut_num > 0)
	{
		ft_putchar('0');
		num_char++;
		cut_num--;
	}
	num_char += ft_strlen(stats.arg);
	ft_putstr(stats.arg);
	return (num_char);
}

int	print_point_arg (struct s_text_stats stats, int num_char, int cut_num)
{
	if (stats.type == 'd' || stats.type == 'i' || stats.type == 'u'
		|| stats.type == 'x' || stats.type == 'X')
		num_char = print_diuxX(stats, num_char, cut_num);
	if (find_type(stats.text) == 'c')
	{
		num_char++;
		if (*stats.arg == '\0')
			ft_putchar('\x00');
		else
			ft_putchar(*stats.arg);
	}
	while (cut_num > 0 && *stats.arg && stats.type == 's')
	{
		ft_putchar(*stats.arg);
		num_char++;
		stats.arg++;
		cut_num--;
	}
	if (stats.type == 'p')
	{
		ft_putstr(stats.arg);
		num_char += ft_strlen(stats.arg);
	}
	return (num_char);
}

int	point_spaces(struct s_text_stats stats, int cut_num, int num_spaces)
{
	if (stats.type == 's' || stats.type == 'p' || stats.type == 'c')
	{
		if ((unsigned int)cut_num < ft_strlen(stats.arg) && stats.type == 's')
			num_spaces = real_spaces(num_spaces, cut_num);
		else
			num_spaces = real_spaces(num_spaces, ft_strlen(stats.arg));
	}
	else if (cut_num != 0)
	{
		if ((unsigned int)cut_num < ft_strlen(stats.arg))
			num_spaces = real_spaces(num_spaces, ft_strlen(stats.arg));
		else
		{
			if (ft_atoi(stats.arg) < 0 && stats.type != 'u')
				num_spaces = real_spaces(num_spaces, 1);
			num_spaces = real_spaces(num_spaces, cut_num);
		}
	}
	else if (cut_num == 0 && *stats.arg != '0')
		num_spaces = real_spaces(num_spaces, ft_strlen(stats.arg));
	return (num_spaces);
}

int	print_point(struct s_text_stats stats, int cut_num, int num_spaces)
{
	int		num_char;

	stats.type = find_type(stats.text);
	num_char = 0;
	if (!stats.arg)
		stats.arg = "(null)\0";
	if (cut_num < 0)
	{
		cut_num = ft_strlen(stats.arg);
		if (ft_atoi(stats.arg) < 0 && (stats.type == 'i'
					|| stats.type == 'd'))
			cut_num--;
	}
	num_spaces = point_spaces(stats, cut_num, num_spaces);
	if (num_spaces > 0)
		num_char += print_spaces(stats, num_spaces, cut_num);
	num_char = print_point_arg (stats, num_char, cut_num);
	if (num_spaces < 0)
		num_char += print_spaces(stats, num_spaces, cut_num);
	return (num_char);
}
