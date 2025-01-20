/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:33:37 by Nathan            #+#    #+#             */
/*   Updated: 2024/11/21 21:04:20 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignednum(int a)
{
	unsigned int	b;

	if (a < 0)
	{
		b = (unsigned int )a;
		return (ft_putnbr(b));
	}
	return (ft_putnbr(a));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_putstr(const char *str)
{
	if (str == NULL)
		return (sizeof(char) * write(1, "(null)", 6));
	return (sizeof(char) * write(1, str, ft_strlen(str)));
}

static int	tprint(const char str, va_list(arg))
{
	char	c;

	if (str == 'c')
	{
		c = va_arg(arg, int);
		return (write(1, &c, 1));
	}
	if (str == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (str == 'd' || str == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (str == 'p')
		return (ft_hexconverter((unsigned long)va_arg(arg, void *)));
	if (str == 'u')
		return (ft_unsignednum(va_arg(arg, unsigned int)));
	if (str == 'x')
		return (ft_inthexconverter(va_arg(arg, int), 1));
	if (str == 'X')
		return (ft_inthexconverter(va_arg(arg, int), 0));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		a;

	va_start(arg, str);
	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			a = a + tprint(str[i + 1], arg);
			if (str[i + 1] == '%')
				a = a + write(1, "%s", 1);
			i += 2;
		}
		if (str[i] != '%' && str[i])
		{
			write(1, &str[i], 1);
			i ++;
			a ++;
		}
	}
	va_end(arg);
	return (a);
}
