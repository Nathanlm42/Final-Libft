/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:16:24 by nle-marc          #+#    #+#             */
/*   Updated: 2024/10/24 03:33:33 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
