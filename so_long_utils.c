/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:49:24 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/18 15:54:27 by loigonza         ###   ########.fr       */
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
		return (ft_free_data(map), 1);
	line = get_next_line(fd);
	if (!line)
		return (ft_free_data(map), 1);
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

int	ft_split_map(char *argv, t_map *map)
{
	char *single_line;
	int fd;
	
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
			return(ft_free_data(map), 1);
		free (single_line);
		single_line = get_next_line(fd);
	}
	map->splited_map = ft_split(map->line, '\n');//el split no s cre bian, no guarda la memoria de la primera linea.
	return (0);
}

int	ft_corners_map(t_map *map)
{
	char *check;
	
	ft_printf("width = %i\n", map->width);
	ft_printf("last line = %s\n", map->splited_map[map->height - 1]);
	if (!ft_strncmp(map->splited_map[0], map->splited_map[map->height - 1], \
	ft_strlen(map->splited_map[0])))
	{
		check = ft_strchr_not_found(map->splited_map[0], '1');
		if (check)
		{
			ft_printf("found something that is not an 1\n");
			ft_free_data(map);
			return (1);
		}
	}
	else
	{
		ft_printf("top and below limits can not differ\n");
		ft_free_data(map);
		return (1);
	}
	return (0);
}

int		ft_sides_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 3;
	while (map->splited_map[0][i])
		i++;
	map->line_width = i - 1;
	ft_printf("line_width is = %i\n", map->line_width);
	ft_printf("first map position = %c\n", map->splited_map[j][0]);
	ft_printf("last map position = %c\n", map->splited_map[j][map->line_width]);
	while (map->splited_map[j])
	{
		if (map->splited_map[j][0] == '1' && map->splited_map[j][map->line_width] == '1')
			j++;
		else
		{
			ft_printf("hola\n");
			ft_free_data(map);
			ft_printf("Map not surronded by walls\n");
			return (1);
		}
	}
	return (0);
}
