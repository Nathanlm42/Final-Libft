/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-marc <nle-marc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:19:25 by Nathan            #+#    #+#             */
/*   Updated: 2024/11/29 19:11:06 by nle-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# ifndef FDMAX
#  define FDMAX 512
# endif
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_strchr(const char *str, int searchchar);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const	char *src, size_t size);
size_t	ft_strlen(const	char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char	*source);
void	ft_bzero(void *s, size_t n);
#endif
