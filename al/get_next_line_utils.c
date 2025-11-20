/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldeir <acaldeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:05:59 by acaldeir          #+#    #+#             */
/*   Updated: 2025/11/19 16:07:07 by acaldeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* calculates the length of the string pointed to by s, excluding the
terminating null byte ('\0'). returns the number of bytes in the string pointed
to by s.*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* Allocates memory using malloc and returns a substring from the string ’s’.
The substring starts at index ’start’ and has a maximum length of ’len’.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			len_s;
	char			*substr;

	i = 0;
	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	if (len > len_s - start)
		len = len_s - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	while (i < len && s[start])
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/* Returns a pointer to the first occurrence of the character c in the string s.
Returns 0 if it doesn't find the character c. */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/* Allocates memory using malloc and returns a new string, which is the result
 of concatenating ’s1’ and ’s2’.*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

/* Extracts a line from storage up to and including the newline character.
Returns the line and updates storage. */
char	*extract_line(char **storage)
{
	char	*line;
	char	*newline_pos;
	char	*temp;
	size_t	line_len;

	if (!*storage)
		return (NULL);
	if (!**storage)
		return (free(*storage), *storage = NULL, NULL);
	newline_pos = ft_strchr(*storage, '\n');
	if (newline_pos)
	{
		line_len = newline_pos - *storage + 1;
		line = ft_substr(*storage, 0, line_len);
		temp = ft_substr(*storage, line_len, ft_strlen(*storage) - line_len);
		if (!line || !temp)
			return (free(line), free(temp), free(*storage),
				*storage = NULL, NULL);
		return (free(*storage), *storage = temp, !**storage
			&& (free(*storage), *storage = NULL), line);
	}
	line = ft_substr(*storage, 0, ft_strlen(*storage));
	if (!line)
		return (free(*storage), *storage = NULL, NULL);
	return (free(*storage), *storage = NULL, line);
}
