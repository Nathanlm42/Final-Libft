/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:49:39 by nle-marc          #+#    #+#             */
/*   Updated: 2024/10/24 01:07:18 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tab;
	unsigned char	*tab2;
	size_t			index;

	tab = (unsigned char *) s1;
	tab2 = (unsigned char *) s2;
	index = 0;
	while (n > index)
	{
		if (tab[index] != tab2[index])
			return (tab[index] - tab2[index]);
		index ++;
	}
	return (0);
}
