/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:36:59 by nle-marc          #+#    #+#             */
/*   Updated: 2024/11/02 02:07:14 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedchar)
{
	int				index;
	unsigned char	to_find;
	unsigned char	*tab;

	index = 0;
	to_find = (unsigned char) searchedchar;
	tab = (unsigned char *) string;
	while (tab[index])
		index ++;
	while (index >= 0)
	{
		if (tab[index] == to_find)
			return ((char *) &string[index]);
		index -- ;
	}
	return (NULL);
}
