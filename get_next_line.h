/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:06:16 by mbotelho          #+#    #+#             */
/*   Updated: 2025/11/20 11:12:24 by mbotelho         ###   ########.fr       */
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

// Functions
char	*get_next_line(int fd);

#endif