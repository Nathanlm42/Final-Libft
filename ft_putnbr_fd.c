/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:02:31 by Nathan            #+#    #+#             */
/*   Updated: 2024/11/02 01:32:54 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ftsizeofdiv(int n)
{
	long int		div;

	div = 1;
	while (n / div)
		div = div * 10;
	return (div);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	tmp;
	long int	div;
	char		res;

	tmp = n;
	div = ftsizeofdiv(tmp) / 10;
	if (tmp < 0)
	{
		tmp = tmp * -1;
		write(fd, "-", 1);
	}
	while (div != 0)
	{
		res = ((tmp / div) % 10 + '0');
		write(fd, &res, 1);
		div = div / 10;
	}
	if (tmp == 0)
		write(fd, "0", 1);
}
