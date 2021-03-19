/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:30:44 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/19 16:29:01 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"
#include <stdio.h>

char	*check_type (char type, char *text, va_list args)
{
	char	*arg;

	arg = NULL;
	if (type == 'd' || type == 'i' || type == 'u'
		|| type == 'x' || type == 'X')
		arg = allint(text, va_arg(args, int));
	if (type == 'p')
		arg = allpointer(text, va_arg(args, unsigned long));
	if (type == 's')
		arg = allchar(va_arg(args, char *));
	if (type == 'c')
		arg = justchar(va_arg(args, int));
	if (type == '%')
		arg = justchar('%');
	return (arg);
}

int	print_text(struct s_text_stats stats)
{
	while (*stats.text != '%' && *stats.text != '\0')
	{
		ft_putchar(*stats.text);
		stats.res++;
		stats.text++;
	}
	return (stats.res);
}

int	print_all(struct s_text_stats stats, va_list args)
{
	while (*stats.text != '\0')
	{
		stats.res = print_text(stats);
		while (*stats.text != '%' && *stats.text != '\0')
			stats.text++;
		if (*stats.text != '\0')
			stats.text++;
		if (*stats.text != '\0' && find_type(stats.text))
		{
			if (num_ast(stats.text) != 0)
				stats.var_spaces = va_arg(args, int);
			stats.num_s = check_num_s(args, stats.text);
			stats.type = find_type(stats.text);
			stats.arg = check_type(stats.type, stats.text, args);
			stats.res = print_star_arg(stats);
			while (*stats.text != stats.type && *stats.text)
				stats.text++;
			if (*stats.text)
				stats.text++;
			if (stats.arg)
				free_all(stats.arg);
		}
	}
	return (stats.res);
}

int	ft_printf(const char *head, ...)
{
	va_list				args;
	struct s_text_stats	stats;

	if (head)
		stats.text = ft_strdup(head);
	stats.res = 0;
	va_start(args, head);
	stats.res = print_all(stats, args);
	if (stats.text)
		free_all(stats.text);
	va_end(args);
	return (stats.res);
}
