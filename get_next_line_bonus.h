/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:26:02 by tnahid            #+#    #+#             */
/*   Updated: 2026/11/18 01:26:41 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_FD
#  define OPEN_FD 1024
# endif

# ifndef SEP
#  define SEP '\n'
# endif

size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *str);

#endif