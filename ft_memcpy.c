/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:09:00 by nle-marc          #+#    #+#             */
/*   Updated: 2024/10/24 00:38:05 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char				*destination;
	char				*source;
	unsigned int		i;

	i = 0;
	destination = (char *) dest;
	source = (char *) src;
	if (!(dest) && !(src))
		return (NULL);
	while (i < size)
	{
		destination[i] = source[i];
		i ++;
	}
	return (dest);
}
