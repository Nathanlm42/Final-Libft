/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:33:15 by nle-marc          #+#    #+#             */
/*   Updated: 2024/10/23 20:31:52 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const	char *src, size_t size)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = ft_strlen(src);
	if (size == 0)
	{
		return (i);
	}
	while (j < size - 1 && src[j])
	{
		dst[j] = src[j];
		j ++;
	}
	dst[j] = '\0';
	return (i);
}
