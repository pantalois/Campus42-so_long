/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:06:10 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/09 18:19:30 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_static(char **stash)
{
	if (*stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

char	*ft_read_file(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (free(buffer), free_static(&stash));
	buffer[0] = '\0';
	bytes_read = 1;
	while (!(ft_strchr(buffer, '\n')) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free_static(&stash));
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
		if (!stash)
			return (free(buffer), free_static(&stash));
	}
	free(buffer);
	if (bytes_read == 0 && !stash)
		return (NULL);
	return (stash);
}

char	*read_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	int		len_stash;
	char	*str;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	if (!stash[i])
		return (free_static(&stash));
	len_stash = ft_strlen_gnl(&stash[i]);
	str = malloc((len_stash + 1) * (sizeof(char)));
	if (!str)
		return (free_static(&stash));
	j = 0;
	while (stash[i] != '\0')
	{
		str[j] = stash[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (free_static(&stash), str);
}

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash || !(ft_strchr(stash, '\n')))
		stash = ft_read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = read_line(stash);
	if (!line)
		return (free_static(&stash));
	stash = clean_stash(stash);
	return (line);
}

/*
//	bytes_read = read(fd, buffer, BUFFER_SIZE);
//if (bytes_read == 0)
//		return (NULL);
	if (!line)
		line = ft_strdup(buffer);
	else
		line = ft_strjoin(line, buffer);
	if (bytes_read < BUFFER_SIZE)
//		buffer[bytes_read] = '\0';
//	if (buffer == NULL)
//		return (NULL);
	if (bytes_read <= 0)
		return (NULL);
//	free(buffer);
	return (line);
}

int main(void)
{
	char *next_line;
	int fd = open("read_error.txt", O_RDONLY);

	while (1)
	{	
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		printf("%s", next_line);
		free(next_line);
	}
	if (!next_line)
		printf("%s", next_line);
	//free(next_line);
	return (0);
}
*/
