/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 09:24:26 by tnahid            #+#    #+#             */
/*   Updated: 2026/11/20 09:44:16 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_buffer(int fd, char *leftover)
{
	char	*buffer;
	ssize_t	rd;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(leftover), NULL);
	rd = 1;
	while (!ft_strchr(leftover, SEP) && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (free(buffer), free(leftover), leftover = NULL, NULL);
		buffer[rd] = '\0';
		leftover = ft_strjoin(leftover, buffer);
		if (!leftover)
			break ;
	}
	free(buffer);
	return (leftover);
}

static char	*get_line(char *leftover)
{
	char	*line;
	char	c;
	char	*tmp;

	if (!leftover || !leftover[0])
		return (NULL);
	tmp = ft_strchr(leftover, SEP);
	if (!tmp)
		return (line = ft_strdup(leftover), line);
	c = tmp[1];
	tmp[1] = '\0';
	line = ft_strdup(leftover);
	tmp[1] = c;
	return (line);
}

char	*get_leftover(char	*leftover)
{
	char	*res;
	char	*tmp;

	tmp = ft_strchr(leftover, SEP);
	if (!tmp || !tmp[1])
		return (free(leftover), NULL);
	res = ft_strdup(tmp + 1);
	if (!res)
		return (free(leftover), NULL);
	free(leftover);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*leftover[OPEN_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover[fd] = read_buffer(fd, leftover[fd]);
	if (!leftover[fd])
		return (NULL);
	line = get_line(leftover[fd]);
	leftover[fd] = get_leftover(leftover[fd]);
	return (line);
}
