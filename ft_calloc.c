/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 03:00:11 by nle-marc          #+#    #+#             */
/*   Updated: 2024/10/24 03:35:10 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementcoumt, size_t elementsize)
{
	size_t			total;
	unsigned char	*memoryblock;
	size_t			index;

	total = elementcoumt * elementsize;
	memoryblock = malloc(total);
	if (memoryblock == NULL)
		return (NULL);
	index = 0;
	while (memoryblock[index])
	{
		memoryblock[index] = 0;
		index ++;
	}
	return (memoryblock);
}
