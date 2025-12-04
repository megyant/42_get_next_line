/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:57:16 by mbotelho          #+#    #+#             */
/*   Updated: 2025/12/04 16:15:02 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	line = ft_strjoin("", buffer[fd]);
	if (ft_isnewline(buffer[fd]))
		return (line);
	bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(line), NULL);
	while (bytes_read)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (ft_isnewline(buffer[fd]))
			break ;
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
	}
	return (line);
}
