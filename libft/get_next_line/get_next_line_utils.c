/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:30:15 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/09 18:20:11 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	j = 0;
	ptr = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!ptr)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i] != '\0')
		ptr[i] = s1[i];
	while (s2[j] != '\0')
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (free(s1), ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	chr;
	char	*str;

	i = 0;
	chr = (char)c;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return (&str[i]);
		else
			i++;
	}
	if (chr == '\0')
		return (&str[i]);
	else
		return (NULL);
}
