/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 00:35:47 by nle-marc          #+#    #+#             */
/*   Updated: 2024/10/27 00:59:38 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*dst;

	index = 0;
	dst = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dst == NULL)
		return (NULL);
	while (s[index])
	{
		dst[index] = (*f)(index, s[index]);
		index ++;
	}
	dst [index] = '\0';
	return (dst);
}
