/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:00:54 by antonmar          #+#    #+#             */
/*   Updated: 2021/02/17 12:32:02 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#ifndef PRINTF_UTILS_H

# define PRINTF_UTILS_H

int					ft_sizeofnum(int n);
int					check_hexsize(unsigned int nbr);
void				ft_strmayus(char *str);
void				ft_strfiller(char *str, char c);
char				*ft_strdup(const char *string);
void				*ft_calloc(size_t nitems, size_t size);
unsigned int		ft_strlen(const char *str);
int					ft_atoi(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *str, int c);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				insert(char c, int count, int pos, char *str);
char				*ft_strrchr(const char *str, int c);
char				*ft_itoa(int n);
char				*ft_unsigned_itoa(unsigned int n);
char				ft_toupper(char c);
char				*ft_tohex(unsigned int nbr);

#endif
