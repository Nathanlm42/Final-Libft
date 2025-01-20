/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 03:06:09 by nle-marc          #+#    #+#             */
/*   Updated: 2024/11/21 18:23:42 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	begin(const	char *s, const char *set)
{
	int		index;
	size_t	start;

	index = 0;
	start = 0;
	while (set[index] && s)
	{
		while (set[index])
		{
			if (*s == set[index])
			{
				start ++;
				s ++;
				index = -1;
			}
			index ++;
		}
		s ++;
	}
	return (start);
}

static size_t	end(const char *s, const char *set)
{
	size_t	index;
	int		index2;
	size_t	pos;

	index2 = 0;
	index = ft_strlen(s) - 1;
	pos = 0;
	while (set[index2])
	{
		while (set[index2])
		{
			if (set[index2] == s[index])
			{
				index2 = 0;
				pos ++;
				break ;
			}
			index2++;
		}
		index --;
	}
	return (ft_strlen(s) - pos);
}

char	*ft_strtrim(char const *s, char const *set)
{
	unsigned int	begin1;
	int				end1;
	char			*dest;

	begin1 = begin(s, set);
	end1 = end(s, set);
	dest = ft_substr(s, begin1, end1 - begin1);
	return (dest);
}
