/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:06:16 by mbotelho          #+#    #+#             */
/*   Updated: 2025/12/09 11:36:50 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Libraries
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// buffer standard
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Main functions
char	*get_next_line(int fd);
int		fill_buffer(int fd, char *buffer);
int		ft_isnewline(char *buffer);

// Auxiliary functions
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif