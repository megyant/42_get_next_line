/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:06:09 by mbotelho          #+#    #+#             */
/*   Updated: 2025/11/21 21:14:13 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buffer)
{
	char	*temp_buffer;
	char	*temp;
	int		bytes_read;

	if (!buffer)
		buffer = ft_strdup("");
	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = 1;
	while ((!ft_strchr(buffer, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		temp = ft_strjoin(buffer, temp_buffer);
		free(buffer);
		buffer = temp;
	}
	free(temp_buffer);
	if (bytes_read < 0)
		return (free(buffer), NULL);
	return (buffer);
}

char	*new_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*clean_buffer(char	*buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new_buffer = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!new_buffer)
		return (free(buffer), NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	dest = malloc((s_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (++i < s_len)
		dest[i] = s[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

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
	char	*strf;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strf = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!strf)
		return (NULL);
	i = -1;
	while (s1[++i])
		strf[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		strf[i] = s2[j];
		i++;
	}
	strf[i] = '\0';
	return (strf);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
