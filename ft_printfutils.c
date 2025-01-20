/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:51:57 by Nathan            #+#    #+#             */
/*   Updated: 2024/11/23 17:36:15 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	char				*point;
	unsigned int		i;

	i = 0;
	point = (char *) s;
	while (i < n)
	{
		point[i] = 0;
		i ++;
	}
}

static size_t	ftsizeofdiv(long long int n)
{
	long int	div;

	div = 1;
	while (n / div)
		div = div * 10;
	return (div);
}

int	ft_putnbr(long int n)
{
	long long int	tmp;
	long long int	div;
	char			res;
	int				fd;
	int				count;

	tmp = n;
	fd = 1;
	div = ftsizeofdiv(tmp) / 10;
	count = 0;
	if (tmp < 0)
	{
		tmp = tmp * -1;
		count = count + write(fd, "-", 1);
	}
	while (div != 0)
	{
		res = ((tmp / div) % 10 + '0');
		count = count + write(fd, &res, 1);
		div = div / 10;
	}
	if (tmp == 0)
		count = count + write(fd, "0", 1);
	return (count * sizeof (char));
}

int	ft_hexconverter(unsigned long ptr)
{
	const char	ref[17] = "0123456789abcdef";
	char		result[20];
	int			index;

	ft_bzero(result, 20);
	index = 15;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	while (ptr > 0)
	{
		result[index --] = ref[ptr % 16];
		ptr /= 16;
	}
	return (write(1, "0x", 2) + ft_putstr(&result[index + 1]));
}

int	ft_inthexconverter(unsigned int nb, int toupper)
{
	const char		ref[] = "0123456789abcdef";
	const char		refmaj[] = "0123456789ABCDEF";
	char			result[20];
	unsigned int	tmp;
	int				i;

	i = 18;
	ft_bzero(result, 20);
	tmp = nb;
	i--;
	if (nb == 0)
		return (ft_putstr("0"));
	while (tmp != 0)
	{
		if (toupper == 0)
			result[i] = refmaj[tmp % 16];
		else
			result[i] = ref[tmp % 16];
		i--;
		tmp = tmp / 16;
	}
	return (write(1, &result[i + 1], ft_strlen(&result[i + 1])));
}
