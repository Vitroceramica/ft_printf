/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:04:45 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/19 16:33:41 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"
#include <stdio.h>

int	check_astpointast(char *text)
{
	while (*text != '*' && *text)
	{
		if (*text == find_type(text))
			break ;
		text++;
	}
	if (*text)
		text++;
	if (*text == '.')
	{
		text++;
		if (*text == '*')
			return (1);
	}
	return (0);
}

int	num_ast(char *text)
{
	int		amount;
	int		num;
	char	type;

	amount = 0;
	num = 0;
	type = find_type(text);
	while (*text != type && type && text != '\0')
	{
		if (*text == '*')
			amount++;
		text++;
	}
	return (amount);
}

int	print_ast(struct s_text_stats stats)
{
	if (find_this_flag(stats.text, '.'))
	{
		if (first_flag(stats.text) == '.')
			stats.res += print_point(stats, stats.var_spaces,
					num_spaces(stats.text));
		else
		{
			stats.var_spaces = check_varspaces(stats.text, stats.var_spaces);
			if (check_astpointast(stats.text) == 1)
				stats.res = astpoint_flag(stats);
			else
				stats.res += print_point(stats, num_cut(stats.text),
						stats.var_spaces);
		}
	}
	else
	{
		stats.var_spaces = check_varspaces(stats.text, stats.var_spaces);
		stats.res += print_nopoint(stats, real_spaces(stats.var_spaces,
					ft_strlen(stats.arg)));
	}
	return (stats.res);
}

int	check_num_s(va_list args, char *text)
{
	int		num_a;
	int		num_s;

	num_a = num_ast(text);
	num_s = 0;
	while (num_a > 1)
	{
		num_s = va_arg(args, int);
		num_a--;
	}
	return (num_s);
}

int	print_star_arg(struct s_text_stats stats)
{
	if (find_this_flag(stats.text, '*') == 1)
		stats.res = print_ast(stats);
	else
		stats.res = print_noast(stats);
	return (stats.res);
}
