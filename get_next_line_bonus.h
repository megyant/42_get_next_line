/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:57:24 by mbotelho          #+#    #+#             */
/*   Updated: 2025/12/04 16:01:20 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// Libraries
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

// buffer standard
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Main functions
char	*get_next_line(int fd);
int		ft_isnewline(char *buffer);

// Auxiliary functions
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif