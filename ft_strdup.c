/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:29:44 by nle-marc          #+#    #+#             */
/*   Updated: 2024/10/26 20:42:17 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*source)
{
	size_t	size;
	char	*dst;

	size = ft_strlen(source);
	dst = (char *)malloc(size + 1);
	size = 0;
	if (dst == NULL)
		return (NULL);
	while (source[size])
	{
		dst[size] = source[size];
		size ++;
	}
	dst[size] = '\0';
	return (dst);
}
