/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:06:13 by mbotelho          #+#    #+#             */
/*   Updated: 2025/12/04 15:37:02 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(0, buffer);
	if (ft_isnewline(buffer))
		return (line);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(line), NULL);
	while (bytes_read)
	{
		line = ft_strjoin(line, buffer);
		if (ft_isnewline(buffer))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

/*int main(void)
{
	int fd = open("test1.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	close(fd);
	return 0;
}*/