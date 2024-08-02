/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:49:24 by loigonza          #+#    #+#             */
/*   Updated: 2024/08/02 15:51:44 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_type(char *argv)
{
	char	*type;
	int		i;

	i = ft_strlen(argv) - 1;
	type = ft_strrchr(argv, '.');
	if (!(argv[i - 3] == '.' && argv[i - 2] == 'b' && argv[i - 1] == 'e'
			&& argv[i] == 'r'))
	{
		ft_write_error(ERRORBER);
		return (1);
	}
	else
		return (0);
}

int	ft_size_map(char *argv, t_map *map)
{
	int		fd;
	char	*line;
	int		j;

	j = 0;
	line = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_write_error(ERRORFD);
		return (ft_free_data(map), 1);
	}
	line = get_next_line(fd);
	if (!line)
		return (ft_free_data(map), 1);
	j = ft_get_the_line(map, line, fd);
	map->height = j;
	if (ft_check_squared(map) == 1)
		return (1);
	close(fd);
	return (0);
}

int	ft_get_the_line(t_map *map, char *line, int fd)
{
	int	i;
	int	j;

	j = 0;
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
	return (j);
}

int	ft_check_squared(t_map *map)
{
	if (map->height == map->width)
	{
		ft_write_error(ERRORSQUARE);
		ft_free_data(map);
		return (1);
	}
	return (0);
}

int	ft_split_map(char *argv, t_map *map)
{
	char	*single_line;
	int		fd;

	map->line = ft_calloc(map->width, (sizeof(char *)));
	if (!map->line)
		return (1);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (1);
	single_line = get_next_line(fd);
	while (single_line)
	{
		map->line = ft_free_strjoin(map->line, single_line);
		if (!map->line)
			return (ft_free_data(map), 1);
		free (single_line);
		single_line = get_next_line(fd);
	}
	map->splited_map = ft_split(map->line, '\n');
	if (!map->splited_map)
		return (1);
	map->cpy_splited_map = ft_split(map->line, '\n');
	if (!map->cpy_splited_map)
		return (1);
	return (0);
}
