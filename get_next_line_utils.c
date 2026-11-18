/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:25:54 by tnahid            #+#    #+#             */
/*   Updated: 2026/11/18 00:56:14 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

char	*ft_strdup(char	*str)
{
	size_t	i;
	char	*dup;

	i = ft_strlen(str);
	dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, i + 1);
	return (dup);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcpy(str + len1, s2, len2 + 1);
	free(s1);
	return (str);
}
