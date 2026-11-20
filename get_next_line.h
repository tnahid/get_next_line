/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 13:46:08 by tnahid            #+#    #+#             */
/*   Updated: 2026/11/18 09:19:41 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h> 
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# ifndef SEP
#  define SEP '\n'
# endif

char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlen(char *str);

#endif
