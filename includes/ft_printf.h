/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:15:53 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/12 16:24:08 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#ifndef PRINTF_H

# define PRINTF_H

struct	text_stats
{
	char	*text;
	char	*arg;
	char	type;
	int		num_s;
	int		var_spaces;
	int		res;
};

int		ft_printf(const char *head, ...);
int		print_nopoint(struct text_stats stats, int spaces);
int		print_point(struct text_stats stats, int cut_num, int num_spaces);
char	*por(char *text);
char	*justchar(char c);
char	*allchar(char *arg);
char	*allint(char *text, int arg);
char	find_flag(char *text);
void	*find_por(char *text);
int		num_spaces(char *text);
char	find_type(char *text);


#endif
