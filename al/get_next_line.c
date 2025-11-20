/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:04:54 by acaldeir          #+#    #+#             */
/*   Updated: 2025/11/20 10:08:46 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Reads a line from the file descriptor 'fd' and returns it.
// Subsequent calls return the next lines until EOF.
// Returns NULL on error or when there are no more lines to read.
char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	ssize_t		bytes_read;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(storage), storage = NULL, NULL);
	bytes_read = 1;
	while (bytes_read > 0 && (!storage || !ft_strchr(storage, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(storage, buffer);
		free(storage);
		storage = temp;
	}
	free(buffer);
	if (bytes_read < 0)
		return (free(storage), storage = NULL, NULL);
	return (extract_line(&storage));
}

//TESTING MAIN AND HELPER FUNCTIONS
//===============================================
 
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		return (1);
	}
	line_count = 1;
	while ((line = get_next_line(fd)))
	{
		printf("Line %d: %s", line_count++, line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
 