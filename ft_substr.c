/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:16:19 by nle-marc          #+#    #+#             */
/*   Updated: 2024/11/02 01:47:03 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*dst;

	index = 0;
	if (ft_strlen(s) <= start)
	{
		dst = malloc(sizeof(char));
		if (dst == NULL)
			return (NULL);
		*dst = '\0';
		return (dst);
	}
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	while (index < len)
	{
		dst[index] = s[start];
		index ++;
		start ++;
	}
	dst[index] = '\0';
	return (dst);
}
