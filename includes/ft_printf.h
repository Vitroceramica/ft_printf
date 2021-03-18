/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:15:53 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/18 20:20:24 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

struct	s_text_stats
{
	char	*text;
	char	*arg;
	char	type;
	int		num_s;
	int		var_spaces;
	int		res;
};

void	*find_por(char *text);
char	find_flag(char *text);
int		find_this_flag(char *text, char flag);
char	find_type(char *text);
char	first_flag(char *text);
char	*justchar(char c);
char	*allpointer(char *text, unsigned long arg);
char	*allchar(char *arg);
char	*allint(char *text, int arg);
int		num_spaces(char *text);
int		check_varspaces (char *text, int var_spaces);
int		real_spaces(int num_spaces, int adjust);
int		print_spaces(struct s_text_stats stats, int num_spaces, int cut_num);
int		num_cut(char *text);
int		num_ast(char *text);
int		check_num_s(va_list args, char *text);
int		print_star_arg(struct s_text_stats stats);
int		print_noast(struct s_text_stats stats);
int		print_nopoint(struct s_text_stats stats, int spaces);
int		print_point(struct s_text_stats stats, int cut_num, int num_spaces);
int		ft_printf(const char *head, ...);
int		print_diuxX(struct s_text_stats stats, int num_char, int cut_num);
int		astpoint_flag(struct s_text_stats stats);

#endif
