/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:28:32 by Nathan            #+#    #+#             */
/*   Updated: 2024/11/21 18:23:00 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	return (count);
}

static void	freealloc(char **dest)
{
	int	a;

	a = 0;
	while (dest[a] != NULL)
	{
		free(dest[a]);
		a ++;
	}
	free(dest);
}

static char	**alloc(const char *s, char c, char **dest)
{
	size_t	index;
	size_t	index2;
	size_t	j;

	index = 0;
	index2 = 0;
	j = 0;
	while (s[index] && j < countwords(s, c))
	{
		while (s[index] == c && s[index])
			index++;
		while (s[index] != c && s[index])
		{
			index++;
			index2++;
		}
		dest[j] = ft_substr(s, index - index2, index2);
		if (dest[j] == NULL)
			return (NULL);
		index2 = 0;
		index++;
		j++;
	}
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**dest;
	int		count;

	count = countwords(s, c);
	dest = (char **)malloc((count + 1) * sizeof(char *));
	if (dest == NULL)
	{
		return (NULL);
	}
	dest[count] = NULL;
	if (alloc(s, c, dest) == NULL)
	{
		freealloc(dest);
		return (NULL);
	}
	return (dest);
}
