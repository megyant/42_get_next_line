/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:06:16 by mbotelho          #+#    #+#             */
/*   Updated: 2025/12/01 19:18:17 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// buffer standard
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Main functions
char	*get_next_line(int fd);
ssize_t	read_and_join(int fd, char **buffer);
char	*extract_line(char **buffer);

// Auxiliary functions
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif