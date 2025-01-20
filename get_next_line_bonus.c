/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:20:18 by Nathan            #+#    #+#             */
/*   Updated: 2024/11/29 19:07:25 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*findline(char *buffer, int fd, int *eof)
{
	char	*dest;

	dest = ft_strdup(buffer);
	while (ft_strchr(dest, '\n') == NULL && *eof > 0)
	{
		*eof = read(fd, buffer, BUFFER_SIZE);
		if (*eof == -1 || fd == -1)
		{
			free (dest);
			*buffer = '\0';
			return (NULL);
		}
		buffer[*eof] = '\0';
		dest = ft_strjoin(dest, buffer);
	}
	return (dest);
}

int	linesize(char *buffer)
{
	int	a;

	a = 0;
	while (buffer [a] != '\n' && buffer[a])
	{
		a ++;
	}
	return (a);
}

char	*returnline(char *buffer, int fd, int *eof)
{
	char	*bigstr;
	char	*dest;

	bigstr = findline(buffer, fd, eof);
	buffer[*eof] = '\0';
	if (bigstr == NULL)
	{
		free (bigstr);
		return (NULL);
	}
	if (ft_strchr(buffer, '\n') != NULL)
		ft_strlcpy(buffer, buffer + linesize(buffer) + 1, BUFFER_SIZE);
	dest = ft_substr(bigstr, 0, linesize(bigstr) + 1);
	free (bigstr);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char		buffer[FDMAX][BUFFER_SIZE + 1] = {0};
	int				eof;
	char			*dest;
	int				linelen;

	eof = BUFFER_SIZE;
	if (fd >= FDMAX || fd < 0)
		return (NULL);
	if (*buffer[fd] == '\0')
		eof = read(fd, buffer[fd], BUFFER_SIZE);
	buffer[fd][eof] = '\0';
	if (eof == -1)
		return (NULL);
	if (*buffer[fd] == '\0')
		return (NULL);
	if (ft_strchr(buffer[fd], '\n') == NULL)
		return (returnline(buffer[fd], fd, &eof));
	else
	{
		dest = ft_substr(buffer[fd], 0, linesize(buffer[fd]) + 1);
		linelen = linesize(buffer[fd]);
		ft_strlcpy(buffer[fd], buffer[fd] + linelen + 1, BUFFER_SIZE - linelen);
	}
	return (dest);
}
