/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 15:07:48 by tnahid            #+#    #+#             */
/*   Updated: 2026/11/13 17:14:06 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd)
{
	char	*buffer;
	ssize_t	ret;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret == -1 || ret == 0)
		return (NULL);
	buffer[ret] = '\0';
	return (buffer);
}

static int	extract_from_buffer(char *buffer, char **saved)
{
	char	*tmp;

	tmp = ft_strchr(buffer, '\n');
	if (tmp)
	{
		*saved = ft_strjoin(*saved, tmp + 1);
		*(tmp + 1) = '\0';
		return (1);
	}
	else
	{
		*saved = ft_strjoin(*saved, buffer);
		if (ft_strlen(buffer) != BUFFER_SIZE)
			return (1);
		return (0);
	}
}

char	*get_next_line(int fd)
{
	static char	*saved = NULL;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{	
		line = saved;
		buffer = read_buffer(fd);
		if (buffer == NULL)
			return (NULL);
		
		if (extract_from_buffer(buffer, &saved))
		{
			line = ft_strjoin(line, buffer);
			break ;
		}
		else
			line = ft_strjoin(line, saved);	
	}
	return (line);
}
