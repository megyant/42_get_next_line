/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:06:16 by mbotelho          #+#    #+#             */
/*   Updated: 2025/11/21 21:12:07 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// buffer standard
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Main functions
char	*get_next_line(int fd);
char	*read_file(int fd, char *buffer);
char	*new_line(char *buffer);
char	*clean_buffer(char	*buffer);

// Auxiliary functions
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif