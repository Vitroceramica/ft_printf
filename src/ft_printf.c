/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:30:44 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/12 18:10:03 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"
#include <stdio.h>

void	*find_por(char *text) //Devuelve el puntero al primer caracter tras el primer % que se encuentre en texto
{
	char *aux;

	aux = text;
	while (*aux != '%' && *aux)
		aux++;
	aux++;
	return (aux);
}

int		num_cut(char *text) //Devuelve el numero de caracteres a imprimir en el flag .
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

char	find_flag(char *text) //Devuelve la primera flag que encuentra desde el puntero pasado como parametro(no va hasta el %)
{
	char	*flags;
	char	*aux;
	int		i;

	flags = "-0.*";
	aux = text;
	i = 0;
	while (*aux != flags[i] && flags[i])
		i++;
	if (flags[i] == '\0')
		return (0);
	if (flags[i] == '0' && aux--)
	{
		if (*aux >= 48 && *aux < 58)
			return (0);
	}
	return (flags[i]);
}

int		find_this_flag(char *text, char flag) //Devuelve 1 si encuentra la flag o 0 si no
{
	char	*aux;
	char type;

	type = find_type(text);
	aux = text;
	while (find_flag(aux) || (*aux >= 48 && *aux < 58))
	{
		if (flag == '0' && find_flag(aux) == '.')
			return (0);
		if (find_flag(aux) == flag)
			return (1);
		aux++;
	}
	return (0);
}

int		num_spaces(char *text) //Devuelve el numero de espacios a imprimer en el primer %, el negativo implica espacios a la derecha
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

char	find_type(char *text) //Devuelve el primer tipo encontrado saltando las flags
{
	char	*types;
	char	*aux;
	int		i;

	types = "cspdiuxX%";
	aux = text;
	while (find_flag(aux) || (*aux >= 48 && *aux < 58))
		aux++;
	i = 0;
	while (*aux != types[i] && types[i])
		i++;
	if (types[i] == '\0')
		return (0);
	return (types[i]);
}

char	*justchar(char c) //devuelve un string ("c\0")
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

char	*allchar(char *arg) //devuelve un string ("arg\0")
{
	char	*str;

	if (!arg)
		return (arg);
	str = ft_strdup(arg);
	return (str);
}

char	first_flag(char *text)
{
	while (*text)
	{
		if (*text == '*')
			return ('*');
		if (*text == '.')
			return ('.');
		text++;
	}
	return (0);
}

int		check_astpointast(char	*text)
{
	while (*text != '*' && *text)
	{
		if (*text == find_type(text))
			break ;
		text++;
	}
	if (*text)
		text++;
	if(*text == '.')
	{
		text++;
		if (*text == '*')
			return (1);
	}
	return (0);
}

int		real_spaces	(int num_spaces, int adjust)
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

char	*allpointer(char *text, unsigned long arg) //Hace una transformacion de unsigned long a hexadecimal y lo mete en un string
{
	char	*str;
	char	*base;
	int		cut;

	str = NULL;
	cut = num_cut(text);
	if (find_type(text) == 'p')
	{
		base = "0123456789abcdef";
		str = ft_calloc(check_hexsize(arg) + 3, 1);
		ft_strfiller(str, '0');
		ft_strfiller(str, 'x');
		if (find_this_flag(text, '.'))
		{
			if (arg == '\0')
				cut++;
			while (cut > check_hexsize(arg))
			{
				ft_strfiller(str, '0');
				cut--;
			}
		}
		if (arg || !find_this_flag(text, '.') || find_this_flag(text, '*'))
			basenum(arg, base, str);
	}
	return (str);
}

char	*allint(char *text, int arg) //encuentra 'd','i','u','x' y 'X' en text y devuelve un string ("arg\0")
{
	char *str;

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

int		num_ast(char *text)
{
	int amount;
	int num;
	char type;

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

int		print_nopoint(struct text_stats stats, int spaces) //reducir mucho
{
	char	c;
	int		num;
	int		num_char;
	char	*aux;

	c = ' ';
	num = spaces;
	num_char = 0;
	aux = stats.text;
	if (!stats.arg)
	{
		stats.arg = "(null)\0";
		num = real_spaces(num, 6);
	}
	if (find_type(stats.text) == 'c' && *stats.arg == '\0')
		num = real_spaces(num, 1);
	if (ft_atoi(stats.arg) < 0 && find_this_flag(stats.text, '0'))
	{
		ft_putchar('-');
		num_char++;
		stats.arg++;
	}
	if (num >= 0)
	{
		if (find_this_flag(stats.text, '0'))
			c = '0';
		while (num > 0)
		{
			ft_putchar(c);
			num_char++;
			num--;
		}
		num_char += ft_strlen(stats.arg);
		ft_putstr(stats.arg);
	}
	if (find_type(stats.text) == 'c' && *stats.arg == '\0')
		{
			ft_putchar('\x00');
			num_char++;
		}
	if (num < 0)
	{
		num_char += ft_strlen(stats.arg);
		ft_putstr(stats.arg);
		while (num < 0)
		{
			ft_putchar(c);
			num_char++;
			num++;
		}
	}
	return (num_char);
}

int		point_spaces(struct text_stats stats, int cut_num, int num_spaces)  //reducir un poco
{
	char c;
	char nowrite;
	char	type;

	c = ' ';
	type = find_type(stats.text);
	nowrite = 0;
	if (cut_num == 0 || stats.type != 'c')
		nowrite = 'T';
	if (type == 's' || type == 'p' || type == 'c')
	{
		if ((unsigned int)cut_num < ft_strlen(stats.arg) && type == 's')
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
			if (ft_atoi(stats.arg) < 0)
				num_spaces = real_spaces(num_spaces, 1);
			num_spaces = real_spaces(num_spaces, cut_num);
		}
	}
	return (num_spaces);
}

int		print_point(struct text_stats stats, int cut_num, int num_spaces) //reducir mucho
{
	char	type;
	char	nowrite;
	int		num_char;
	char	c;

	type = find_type(stats.text);
	num_char = 0;
	nowrite = 0;
	c = ' ';
	if (!stats.arg)
		stats.arg = "(null)\0";
	if (cut_num < 0)
	{
		cut_num = ft_strlen(stats.arg);
		if (ft_atoi(stats.arg) < 0)
			cut_num--;
	}
	if (cut_num == 0 || type != 'c')
		nowrite = 'T';
	num_spaces = point_spaces(stats, cut_num, num_spaces);
	while (num_spaces > 0)
	{
		if (find_this_flag(stats.text, '0') && nowrite != 'T')
			c = '0';
		ft_putchar(c);
		num_char++;
		num_spaces--;
	}
	if (type == 'd' || type == 'i' || type == 'u'
	|| type == 'x' || type == 'X')
	{
		if (*stats.arg == '0')
			stats.arg = "\0";
		if (ft_atoi(stats.arg) < 0)
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
	}
	if (find_type(stats.text) == 'c')
	{
		num_char++;
		if (*stats.arg == '\0')
			ft_putchar('\x00');
		else
			ft_putchar(*stats.arg);
	}
	while (cut_num > 0 && *stats.arg && type == 's')
	{
		ft_putchar(*stats.arg);
		num_char++;
		stats.arg++;
		cut_num--;
	}
	if (type == 'p')
		{
			ft_putstr(stats.arg);
			num_char += ft_strlen(stats.arg);
		}
	while (num_spaces < 0)
	{
		ft_putchar(c);
		num_char++;
		num_spaces++;
	}
	return (num_char);
}

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

int		check_varspaces (char *text, int var_spaces)
{
	if (find_this_flag(text, '-'))
		{
			if (var_spaces > 0)
			var_spaces = var_spaces * -1;
		}
	return (var_spaces);
}

int		print_ast(struct text_stats stats)
{
	if (find_this_flag(stats.text, '.'))
	{
		if (first_flag(stats.text) == '.')
			stats.res += print_point(stats, stats.var_spaces, num_spaces(stats.text));
		else
		{
			stats.var_spaces = check_varspaces(stats.text, stats.var_spaces);
			if (check_astpointast(stats.text) == 1)
				stats.res += print_point(stats, stats.num_s, stats.var_spaces);
			else
				stats.res += print_point(stats, num_cut(stats.text), stats.var_spaces);
		}
	}
	else
	{
		stats.var_spaces = check_varspaces(stats.text, stats.var_spaces);
		stats.res += print_nopoint(stats, real_spaces(stats.var_spaces, ft_strlen(stats.arg)));
	}
	return (stats.res);
}

int		print_noast(struct text_stats stats)
{
	if (find_this_flag(stats.text, '.'))
		stats.res += print_point(stats, num_cut(stats.text),
		num_spaces(stats.text));
	else
		stats.res += print_nopoint(stats, real_spaces(num_spaces(stats.text),
		ft_strlen(stats.arg)));
	return (stats.res);
}

int		check_num_s(va_list args, char *text)
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

int		print_star_arg(struct text_stats stats)
{
	if (find_this_flag(stats.text, '*') == 1)
		stats.res = print_ast(stats);
	else
		stats.res = print_noast(stats);
	return (stats.res);
}

int		print_all(struct text_stats stats, va_list args)
{
	while (*stats.text != '\0')
	{
		while (*stats.text != '%' && *stats.text != '\0')
		{
			ft_putchar(*stats.text);
			stats.res++;
			stats.text++;
		}
		while (*stats.text != '%' && *stats.text != '\0')
			stats.text++;
		if (*stats.text != '\0')
		{
			stats.text++;
			if (num_ast(stats.text) != 0)
				stats.var_spaces = va_arg(args, int);
			stats.num_s = check_num_s(args, stats.text);
			stats.type = find_type(stats.text);
			stats.arg = check_type(stats.type, stats.text, args);
			stats.res = print_star_arg(stats);
			while (*stats.text != stats.type && *stats.text)
				stats.text++;
			(*stats.text) ? stats.text++ : NULL ;
		}
	}
	return (stats.res);
}

int		ft_printf(const char *head, ...)
{
	va_list 			args;
	struct				text_stats	stats;

	stats.text = ft_strdup(head);
	stats.res = 0;
	va_start(args, head);
	stats.res = print_all(stats, args);
	va_end(args);
	free_all(stats.text);
	free_all(stats.arg);
	return (stats.res);
}
