/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:24:45 by nle-marc          #+#    #+#             */
/*   Updated: 2024/11/21 18:22:16 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rempl(char *dst, char *src, size_t index2, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		dst[index2] = src[index2];
		index2 --;
		index ++;
	}
	return (dst);
}

void	*ft_memmove(void *destination, void *source, size_t size )
{
	size_t	index;
	size_t	index2;
	char	*dst;
	char	*src;

	dst = (char *)destination;
	src = (char *) source;
	index = 0;
	index2 = size - 1;
	if (!(dst) && !(src))
		return (NULL);
	if (dst > src)
	{
		return (rempl(dst, src, index2, size));
	}
	while (index < size)
	{
		dst[index] = src[index];
		index ++;
	}
	return (dst);
}
