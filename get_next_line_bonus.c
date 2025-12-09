/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:57:16 by mbotelho          #+#    #+#             */
/*   Updated: 2025/12/09 15:03:42 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			is_newline;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	is_newline = 0;
	while (!is_newline && fill_buffer(fd, buffer[fd]))
	{
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
			return (NULL);
		is_newline = ft_isnewline(buffer[fd]);
	}
	return (line);
}

/*int	main(void)
{
	int		fd1 = open("test1.txt", O_RDONLY);
	int		fd2 = open("test2.txt", O_RDONLY);
	int		fd3 = open("test3.txt", O_RDONLY);
	char	*line1;
	char	*line2;
	char	*line3;

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (1);

	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);

		if (!line1 && !line2 && !line3)
			break ;

		if (line1)
		{
			printf("test1: %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("test2: %s", line2);
			free(line2);
		}
		if (line3)
		{
			printf("test3: %s", line3);
			free(line3);
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/