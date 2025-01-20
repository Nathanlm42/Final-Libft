/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:35:14 by Nathan            #+#    #+#             */
/*   Updated: 2024/11/23 17:30:21 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putnbr(long int n);
int		ft_putstr(const	char *str);
int		ft_hexconverter(unsigned long ptr);
int		ft_unsignednum(int a);
int		ft_inthexconverter(unsigned int nb, int toupper);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
#endif
