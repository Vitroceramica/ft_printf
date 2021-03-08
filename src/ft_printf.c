/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:30:44 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/08 19:19:37 by antonmar         ###   ########.fr       */
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

	str = calloc(2, 1);
	ft_strfiller(str, c);
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

	str = NULL;
	if (find_type(text) == 'p')
	{
		str = ft_calloc(check_hexsize(arg) + 3, 1);
		ft_strfiller(str, '0');
		ft_strfiller(str, 'x');
		base = "0123456789abcdef";
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

void	print_arg(char *text, char *arg, int spaces) //imprime el argumento con el numero de espacios o 0s correspondiente
{
	char	c;
	int		num;
	char	*aux;

	c = ' ';
	num = spaces;
	aux = text;
	if (!arg)
	{
		arg = "(null)\0";
		num = real_spaces(num, 6);
	}
	/*if (ft_atoi(arg) < 0)
		{
			ft_putchar('-');
			arg++;
		}*/
	if (num >= 0)
	{
		if (find_this_flag(text, '0'))
			c = '0';
		while (num > 0)
		{
			ft_putchar(c);
			num--;
		}
		ft_putstr(arg);
	}
	if (num < 0)
	{
		ft_putstr(arg);
		while (num < 0)
		{
			ft_putchar(c);
			num++;
		}
	}
}

void	print_point(char *text, char *arg, int cut_num, int num_spaces) // Imprime el numero de carácteres y espacios seleccionados de arg
{
	char	type;
	char	nowrite;
	char	c;

	type = find_type(text);
	nowrite = 0;
	c = ' ';
	if (!arg)
		arg = "(null)\0";
	if (cut_num < 0)
		cut_num = ft_strlen(arg);
	if (cut_num == 0)
		nowrite = '\0';
	else if ((unsigned int)cut_num < ft_strlen(arg))
		num_spaces = real_spaces(num_spaces, cut_num);
	else
		num_spaces = real_spaces(num_spaces, ft_strlen(arg));
	while (num_spaces > 0)
	{
		if (find_this_flag(text, '0') && nowrite != '\0')
			c = '0';
		ft_putchar(c);
		num_spaces--;
	}
	if (type == 'd' || type == 'i' || type == 'u'
	|| type == 'x' || type == 'X')
	{
		if (*arg == '0')
			arg = "\0";
		if (ft_atoi(arg) < 0)
		{
			ft_putchar('-');
			arg++;
		}
		cut_num = cut_num - ft_strlen(arg);
		while (cut_num > 0)
		{
			ft_putchar('0');
			cut_num--;
		}
		ft_putstr(arg);
	}
	if (type == 's' || type == 'p')
	{
		while (cut_num > 0 && *arg)
		{
			ft_putchar(*arg);
			arg++;
			cut_num--;
		}
	}
	while (num_spaces < 0)
	{
		ft_putchar(c);
		num_spaces++;
	}
}

int		ft_printf(const char *head, ...)
{
	va_list args;
	char	*text;
	char	*arg;
	char	type;
	int		num_a;
	int		num_s;

	text = ft_strdup(head);
	num_a = 0;
	num_s = 0;
	va_start(args, head);
	while (*text != '\0')
	{
		while (*text != '%' && *text != '\0')
		{
			ft_putchar(*text);
			text++;
		}
		if (*text != '\0')
		{
			text++;
			num_a = num_ast(text);
			if (num_a != 0)
			{
				while (num_a > 0)
				{
					num_s = va_arg(args, int);
					num_a--;
				}
			}
			type = find_type(text);
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
			if (find_this_flag(text, '*') == 1)
			{
				if (find_this_flag(text, '.'))
				{
					if (first_flag(text) == '.')
						print_point(text, arg, num_s, num_spaces(text));
					else
						print_point(text, arg, num_cut(text), num_s + ft_strlen(arg));
				}
				else
				{
					print_arg(text, arg, real_spaces(num_s, ft_strlen(arg)));
				}
			}
			else
			{
				if (find_this_flag(text, '.'))
					print_point(text, arg, num_cut(text),
					num_spaces(text));
				else
					print_arg(text, arg, real_spaces(num_spaces(text), ft_strlen(arg)));
			}
		}
		while (*text != type && *text)
			text++;
		if (*text)
			text++;
	}
	return (0);
}
