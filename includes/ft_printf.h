/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:15:53 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/01 15:59:03 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#ifndef PRINTF_H

# define PRINTF_H

int		ft_printf(const char *head, ...);
void	print_arg(char *text, char *arg, int spaces);
void	print_point(char *text, char *arg, int cut_num, int num_spaces);
char	*por(char *text);
char	*justchar(char c);
char	*allchar(char *arg);
char	*allint(char *text, int arg);
char	find_flag(char *text);
char	*find_por(char *text);
int		num_spaces(char *text, char *arg);
char	find_type(char *text);


#endif
