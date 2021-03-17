/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:35:46 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/17 14:28:53 by antonmar         ###   ########.fr       */
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
	//TODO ESTO FUNCIONA (ESPACIOS CON TODOS LOS TIPOS Y FLAGS DE LOS ESPACIOS - Y 0)
	/*ft_printf("comemeel%012icomemierda\n", 23);
	ft_printf("comemeel%012scomemierda\n", a);
	ft_printf("comemeel%012pcomemierda\n", &a);
	ft_printf("comemeel%012dcomemierda\n", 23);
	ft_printf("comemeel%012xcomemierda\n", 23);
	ft_printf("comemeel%012Xcomemierda\n", 23);
	ft_printf("comemeel%012ccomemierda\n", 'a');
	ft_printf("comemeel%012%2comemierda\n");
	ft_printf("%7.5s\n", "yolo");
	ft_printf("%3.s\n", "hola");
	ft_printf("%3.1s\n", NULL);
	ft_printf("%.6i\n", -3);
	ft_printf("%07i\n", -54);
	ft_printf("%5.i\n", 0);
	ft_printf("%5c\n", NULL);
	ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	ft_printf("comemeel%.*i\n", 2, 42);*/

	//ft_printf("%-*.*s\n", "0");
	printf("%-*.*s\n", "0");
	system("leaks a.out -fullContent");
}
