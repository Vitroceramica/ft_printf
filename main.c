/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:35:46 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/16 14:29:10 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/ft_printf_utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int		main()
{
	char 	*a = "cipote";
	/*
	//TODO ESTO FUNCIONA (ESPACIOS CON TODOS LOS TIPOS Y FLAGS DE LOS ESPACIOS - Y 0)
	printf("original:\n");
	printf("comemeel%012icomemierda\n", 23);
	printf("mio:\n");
	ft_printf("comemeel%012icomemierda\n", 23);
	printf("original:\n");
	printf("comemeel%012scomemierda\n", a);
	printf("mio:\n");
	ft_printf("comemeel%012scomemierda\n", a);
	printf("original:\n");
	printf("comemeel%012pcomemierda\n", &a);
	printf("mio:\n");
	ft_printf("comemeel%012pcomemierda\n", &a);
	printf("original:\n");
	printf("comemeel%012dcomemierda\n", 23);
	printf("mio:\n");
	ft_printf("comemeel%012dcomemierda\n", 23);
	printf("original:\n");
	printf("comemeel%012xcomemierda\n", 23);
	printf("mio:\n");
	ft_printf("comemeel%012xcomemierda\n", 23);
	printf("original:\n");
	printf("comemeel%012Xcomemierda\n", 23);
	printf("mio:\n");
	ft_printf("comemeel%012Xcomemierda\n", 23);
	printf("original:\n");
	printf("comemeel%012ccomemierda\n", 'a');
	printf("mio:\n");
	ft_printf("comemeel%012ccomemierda\n", 'a');
	printf("original:\n");
	printf("comemeel%012%2comemierda\n");
	printf("mio:\n");
	ft_printf("comemeel%012%2comemierda\n");
	ft_printf("%7.5s\n", "yolo");
	printf("%7.5s\n", "yolo");
	ft_printf("%3.s\n", "hola");
	printf("%3.s\n", "hola");
	ft_printf("%3.1s\n", NULL);
	printf("%3.1s\n", NULL);
	ft_printf("%.6i\n", -3);
	printf("%.6i\n", -3);
	ft_printf("%07i\n", -54);
	printf("%07i\n", -54);
	ft_printf("%5.i\n", 0);
	printf("%5.i\n", 0);
	ft_printf("%5c\n", NULL);
	printf("%5c\n", NULL);
	ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	printf("%%-*.3s LYDI == |%-*.3s|", 5, "LYDI");
}
	*/
	ft_printf("comemeel%.*i\n", 2, 42);
	//printf("comemeel%.*i\n", 2, 42);
	system("leaks a.out -fullContent");
}
