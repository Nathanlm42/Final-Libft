/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:43:40 by nle-marc          #+#    #+#             */
/*   Updated: 2024/10/26 23:34:42 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int n, size_t count)
{
	char			*point;
	unsigned int	i;

	point = (char *) pointer;
	i = 0;
	while (i < count)
	{
		point[i] = n;
		i ++;
	}
	return (point);
}
