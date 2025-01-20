/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:10:16 by nle-marc          #+#    #+#             */
/*   Updated: 2024/10/27 00:18:32 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	index;
	size_t	index2;
	size_t	size;

	index = 0;
	index2 = 0;
	size = ft_strlen(tofind);
	while (str[index] && index < len)
	{
		while (str[index + index2] == tofind[index2]
			&& index + index2 < len && tofind[index2])
		{
			index2 ++;
			if (index2 == size)
			{
				return ((char *) &str[index]);
			}
		}
		index2 = 0;
		index ++;
	}
	if (*tofind == '\0')
		return ((char *) str);
	return (NULL);
}
