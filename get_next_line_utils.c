/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:06:09 by mbotelho          #+#    #+#             */
/*   Updated: 2025/12/09 11:24:48 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

int	fill_buffer(int fd, char *buffer)
{
	int		bytes_read;

	if (buffer[0] != '\0')
		return (1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (0);
	buffer[bytes_read] = '\0';
	return (1);
}

int	ft_isnewline(char *buffer)
{
	size_t	i;
	size_t	j;
	int		found;

	i = 0;
	j = 0;
	found = 0;
	while (buffer[i])
	{
		if (found)
		{
			buffer[j] = buffer[i];
			j++;
		}
		if (buffer[i] == '\n')
			found = 1;
		buffer[i] = '\0';
		i++;
	}
	buffer[j] = '\0';
	return (found);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nstr;
	size_t	i;
	size_t	j;

	if (!s2 || s2[0] == '\0')
		return (s1);
	nstr = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!nstr)
		return (free (s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		nstr[i++] = s1[j++];
	j = 0;
	while (s2[j] && s2[j] != '\n')
		nstr[i++] = s2[j++];
	if (s2[j] == '\n')
		nstr[i++] = '\n';
	nstr[i] = '\0';
	free(s1);
	return (nstr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
