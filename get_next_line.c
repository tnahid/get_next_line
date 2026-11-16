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

static char	*read_buffer(int fd, char *chyata)
{
	char	*buffer;
	ssize_t	rd;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(chyata);
		return (NULL);
	}
	rd = 1;
	while ((ft_strchr(chyata, '\n') == -1) && rd > 1)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			free(chyata);
			return (NULL);
		}
		buffer[rd] = '\0';
		chyata = ft_strjoin(chyata, buffer);
	}
	free(buffer);
	return (chyata);
}

static char	*get_line(char *chyata)
{
	char	*line;
	size_t	i;

	if (!chyata || !chyata[0])
		return(NULL);
	i = ft_strchr(chyata, '\n');
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	ft_strlcpy(line, chyata, i + 2);
	return (line);
}

static char	*get_chyata(char *chyata)
{
	char	*res;
	size_t	i;
	size_t	j;

	j = ft_strlen(chyata);
	i = ft_strchr(chyata, '\n');
	if (!chyata[i + 1] || !chyata[i])
		return (NULL);
	res = malloc(j - i);
	if (!res)
	{
		free(chyata);
		return (NULL);
	}
	ft_strlcpy(res, chyata + i + 1, j - i);
	free(chyata);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*chyata;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!chyata)
	{
		chyata = malloc(1);
		if (!chyata)
			return (NULL);
		chyata[0] = '\0';
	}
	chyata = read_buffer(fd, chyata);
	if (!chyata)
		return (NULL);
	line = get_line(chyata);
	chyata = get_chyata(chyata);
	return(NULL);
}
