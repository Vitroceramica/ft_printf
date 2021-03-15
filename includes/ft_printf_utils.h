/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:00:54 by antonmar          #+#    #+#             */
/*   Updated: 2021/03/15 17:56:12 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#ifndef PRINTF_UTILS_H

# define PRINTF_UTILS_H

int					ft_sizeofnum(int n);
int					check_hexsize(unsigned long nbr);
void				basenum(unsigned long num, char *base, char *str);
void				ft_strmayus(char *str);
void				ft_strfiller(char *str, char c);
char				*ft_strdup(const char *string);
void				*ft_calloc(size_t nitems, size_t size);
unsigned int		ft_strlen(const char *str);
int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char *s);
char				*ft_itoa(int n);
char				*ft_unsigned_itoa(unsigned int n);
char				*ft_tohex(unsigned long nbr);
void				free_all(char *to_free);

#endif
