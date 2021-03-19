/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:25:24 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/19 16:20:51 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"
#include <stdio.h>

int	print_nopoint_arg(struct s_text_stats stats, int num_char)
{
	num_char += ft_strlen(stats.arg);
	ft_putstr(stats.arg);
	if (find_type(stats.text) == 'c' && *stats.arg == '\0')
	{
		ft_putchar('\x00');
		num_char++;
	}
	return (num_char);
}

int	print_nopoint(struct s_text_stats stats, int spaces)
{
	char	c;
	int		num_char;

	c = ' ';
	num_char = 0;
	if (!stats.arg)
	{
		stats.arg = "(null)\0";
		spaces = real_spaces(spaces, 6);
	}
	if (find_type(stats.text) == 'c' && *stats.arg == '\0')
		spaces = real_spaces(spaces, 1);
	if (ft_atoi(stats.arg) < 0 && find_this_flag(stats.text, '0')
		&& stats.type != 'u')
	{
		ft_putchar('-');
		num_char++;
		stats.arg++;
	}
	if (spaces > 0)
		num_char += print_spaces(stats, spaces, 0);
	num_char = print_nopoint_arg(stats, num_char);
	if (spaces < 0)
		num_char += print_spaces(stats, spaces, 0);
	return (num_char);
}

int	print_noast(struct s_text_stats stats)
{
	if (find_this_flag(stats.text, '.'))
		stats.res += print_point(stats, num_cut(stats.text),
				num_spaces(stats.text));
	else
		stats.res += print_nopoint(stats, real_spaces(num_spaces(stats.text),
					ft_strlen(stats.arg)));
	return (stats.res);
}
