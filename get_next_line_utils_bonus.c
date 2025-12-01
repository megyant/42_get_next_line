/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:36:12 by mbotelho          #+#    #+#             */
/*   Updated: 2025/12/01 19:36:27 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

ssize_t	read_and_join(int fd, char **buffer)
{
	char	temp[BUFFER_SIZE + 1];
	char	*new_buffer;
	ssize_t	bytes_read;

	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (bytes_read);
	temp[bytes_read] = '\0';
	new_buffer = ft_strjoin(*buffer, temp);
	if (!new_buffer)
		return (-1);
	free(*buffer);
	*buffer = new_buffer;
	return (bytes_read);
}

char	*extract_line(char **buffer)
{
	char	*line;
	char	*newline_position;
	size_t	line_len;
	size_t	i;

	if (!buffer || !*buffer)
		return (NULL);
	newline_position = ft_strchr(*buffer, '\n');
	if (newline_position)
		line_len = newline_position - *buffer + 1;
	else
		line_len = ft_strlen(*buffer);
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < line_len)
		line[i] = (*buffer)[i];
	line[i] = '\0';
	newline_position = *buffer;
	if (ft_strchr(*buffer, '\n') && *(ft_strchr(*buffer, '\n') + 1))
		*buffer = ft_strjoin(NULL, ft_strchr(*buffer, '\n') + 1);
	else
		*buffer = NULL;
	return (free(newline_position), line);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	if (s2)
		s2_len = ft_strlen(s2);
	result = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}