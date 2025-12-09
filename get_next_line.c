/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:06:13 by mbotelho          #+#    #+#             */
/*   Updated: 2025/12/09 15:04:57 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			is_newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	is_newline = 0;
	while (!is_newline && fill_buffer(fd, buffer))
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(line), NULL);
		is_newline = ft_isnewline(buffer);
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
	printf("\n");
}*/