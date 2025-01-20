/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:02:28 by nle-marc          #+#    #+#             */
/*   Updated: 2024/11/02 02:05:54 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const	char *src, size_t size)
{
	size_t	index;
	size_t	index1;
	size_t	len1;
	size_t	len;

	index = ft_strlen(dst);
	len1 = index;
	len = ft_strlen(src);
	index1 = 0;
	if (index >= size)
		return (len + size);
	while (index < size - 1 && src[index1])
	{
		dst[index] = src[index1];
		index ++;
		index1 ++;
	}
	dst[index] = '\0';
	return (len + len1);
}
