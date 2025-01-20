/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 00:03:18 by nle-marc          #+#    #+#             */
/*   Updated: 2024/10/27 00:12:28 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index;
	size_t	index2;
	char	*dst;

	index = 0;
	index2 = 0;
	dst = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[index])
	{
		dst[index] = s1[index];
		index ++;
	}
	while (s2[index2])
	{
		dst[index] = s2[index2];
		index ++;
		index2 ++;
	}
	dst[index] = '\0';
	return (dst);
}
