/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:35:10 by mbotelho          #+#    #+#             */
/*   Updated: 2025/12/01 19:35:45 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffers[1024];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read_and_join(fd, &buffer);
		if (bytes_read < 0)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
	}
	line = extract_line(&buffer);
	return (line);
}