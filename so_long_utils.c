/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:49:24 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/17 19:12:49 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_type(char *argv)
{
	char *type;

	type = ft_strrchr(argv, '.');
	if (!ft_strncmp(type, ".ber", ft_strlen(type)))
		return (1);
	
	else
		return (0);
}

int	ft_size_map(char *argv, t_map *map)
{
	int		fd;
	char	*line = NULL;
	int		i;
	int		j;

	j = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{
		i = 0;
		while (line[i])
			i++;
		map->width += i;
		j++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map->height = j;
	return (0);
}

char **ft_split_map(char *argv, t_map *map)
{
	char *single_line;
	int fd;
	//char	**splited_map;
	

	map->line = ft_calloc(map->width, (sizeof(char *)));
	if (!map->line)
		return (NULL);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	single_line = get_next_line(fd);
	while (single_line)
	{
		map->line = ft_free_strjoin(map->line, single_line);
		if (!map->line)
			return(free(single_line), NULL);
		free (single_line);
		single_line = get_next_line(fd);
	}
	return (NULL);
}
