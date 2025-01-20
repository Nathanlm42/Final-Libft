/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:08:48 by Nathan            #+#    #+#             */
/*   Updated: 2024/11/02 02:02:38 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	sizeofint(long int n)
{
	size_t		index;

	index = 0;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		index ++;
	}
	return (index);
}

static char	*allocint(size_t size, int n, char *dest)
{
	if (n == 0)
	{
		dest = malloc(2 * sizeof(char));
		if (dest == NULL)
			return (NULL);
		dest[0] = '0';
		dest[1] = '\0';
	}
	else if (n < 0)
	{
		dest = malloc ((size + 2) * sizeof(char));
		if (dest == NULL)
			return (NULL);
		dest[0] = '-';
		dest[size + 1] = '\0';
	}
	else
	{
		dest = malloc(((size + 1) * sizeof(char)));
		if (dest == NULL)
			return (NULL);
		dest[size] = '\0';
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char		*dest;
	size_t		index;
	long int	tmp;
	size_t		size;

	index = 0;
	dest = NULL;
	tmp = n;
	size = sizeofint(tmp);
	dest = allocint(size, n, dest);
	if (dest == NULL)
		return (NULL);
	if (tmp < 0)
	{
		tmp = tmp * -1;
		index ++;
		size ++;
	}
	while (tmp > 0)
	{
		size --;
		dest[size] = ((tmp) % 10) + '0';
		tmp = tmp / 10;
	}
	return (dest);
}
