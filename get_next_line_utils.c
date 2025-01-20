/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:20:45 by Nathan            #+#    #+#             */
/*   Updated: 2024/11/23 17:39:50 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int searchchar)
{
	int				index;
	unsigned char	tofind;

	index = 0;
	tofind = (unsigned char)searchchar;
	while (str[index])
	{
		if (str[index] == tofind)
		{
			return ((char *) &str[index]);
		}
		index ++;
	}
	if (tofind == '\0')
		return ((char *) &str[index]);
	return (NULL);
}

size_t	ft_strlen(const	char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}

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
	while (j < size - 1)
	{
		dst[j] = src[j];
		j ++;
	}
	dst[j] = '\0';
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
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
	free (s1);
	return (dst);
}
