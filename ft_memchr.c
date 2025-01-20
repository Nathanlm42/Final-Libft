/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:01:14 by nle-marc          #+#    #+#             */
/*   Updated: 2024/10/23 21:25:55 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryblock, int searchedchar, size_t size)
{
	unsigned char	*tmp;
	unsigned char	tofind;
	size_t			index;

	tmp = (unsigned char *) memoryblock;
	index = 0;
	tofind = (unsigned char) searchedchar;
	while (size > index)
	{
		if (tmp[index] == tofind)
			return (&tmp[index]);
		index ++;
	}
	return (NULL);
}
