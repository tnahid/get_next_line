/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:25:47 by tnahid            #+#    #+#             */
/*   Updated: 2026/11/17 00:33:53 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd, char *leftover)
{
	char	*buffer;
	ssize_t	rd;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(leftover);
		return (NULL);
	}
	rd = 1;
	while (!ft_strchr(leftover, SEP) && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			free(leftover);
			return (NULL);
		}
		buffer[rd] = '\0';
		leftover = ft_strjoin(leftover, buffer);
	}
	free(buffer);
	return (leftover);
}

static char	*get_line(char *leftover)
{
	char	*line;
	size_t	i;

	if (!leftover || !*leftover)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != SEP)
		i++;
	if (leftover[i] == SEP)
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, leftover, i + 1);
	return (line);
}

static char	*get_leftover(char *leftover)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	while (leftover[i] && leftover[i] != SEP)
		i++;
	if (!leftover[i] || !leftover[i + 1])
	{
		free(leftover);
		return (NULL);
	}
	j = ft_strlen(leftover);
	res = malloc(j - i);
	if (!res)
	{
		free(leftover);
		return (NULL);
	}
	ft_strlcpy(res, leftover + i + 1, j - i);
	free(leftover);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = read_buffer(fd, leftover);
	if (!leftover)
		return (NULL);
	line = get_line(leftover);
	leftover = get_leftover(leftover);
	return (line);
}
