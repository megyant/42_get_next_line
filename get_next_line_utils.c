/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotelho <mbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:06:09 by mbotelho          #+#    #+#             */
/*   Updated: 2025/12/04 15:38:12 by mbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

int	ft_isnewline(char *buffer)
{
	size_t	i;
	size_t	j;
	int		is_line;

	i = 0;
	j = 0;
	is_line = 0;
	while (buffer[i])
	{
		if (is_line)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			is_line = 1;
		buffer[i++] = '\0';
	}
	return (is_line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nstr;
	size_t	i;
	size_t	j;

	if (!s2[0])
		return (0);
	nstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!nstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		nstr[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j] != '\n' && s2[j])
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
