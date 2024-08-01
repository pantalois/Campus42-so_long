/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:49:24 by loigonza          #+#    #+#             */
/*   Updated: 2024/08/01 13:04:26 by loigonza         ###   ########.fr       */
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
	if (map ->height == map->width)
	{
		ft_printf("Squared map\n");
		return (1);
	}
	close(fd);
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
	if (!map->splited_map)
		return (1);
	map->cpy_splited_map = ft_split(map->line, '\n');
	if (!map->cpy_splited_map)
		return (1);
	return (0);
}

int	ft_corners_map(t_map *map)
{
	char *check;
	
	if (map->splited_map[map->height - 1] && !ft_strncmp(map->splited_map[0], map->splited_map[map->height - 1], \
	ft_strlen(map->splited_map[0])))
	{	
		check = ft_strchr_not_found(map->splited_map[0], '1');
		if (check)
		{
			ft_printf("Found something that is not a 1\n");
			ft_free_data(map);
			return (1);
		}
	}
	else if (!map->splited_map[map->height - 1])
	{
		ft_printf("Empty line on map\n");
		ft_free_data(map);
		return (1);
	}
	else
	{
		ft_printf("Top and below limits can not differ\n");
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
	j = 0;
	while (map->splited_map[j][i])
		i++;
	map->first_line_width = i - 1;
	i = 0;
	j++;
	while (map->splited_map[j][i])
	{
		i = 0;
		while (map->splited_map[j][i])
			i++;
		map->line_width = i - 1;
		if (i >= 39)
		{
			ft_printf("Map out of the window limits\n");
			ft_free_data(map);
			return (1);
		}
		if (map->height >= 22)
		{
			ft_printf("Map out of the window limits\n");
			ft_free_data(map);
			return (1);
		}
		if (map->first_line_width != map->line_width)
		{
			ft_printf("All the sides of the map are not equal\n");
			ft_free_data(map);
			return (1);
		}
		j++;
	}
	ft_printf("width = %i\n", map->line_width + 1);
	ft_printf("height = %i\n", map->height);
	if (map->height == map->line_width + 1)
	{
		ft_printf("Squared map\n");
		return (1);
	}
	//Funcion para checkear espacios en blanco dentro del mapa
	//seguramente la cambiamos a otro utils
	j = 0;
	while (map->splited_map[j])
	{
		i = 0;
		while (map->splited_map[j][i])
		{
			if ((map->splited_map[j][i] >= 9 && map->splited_map[j][i] <= 13) \
					|| map->splited_map[j][i] == 32)
			{
				ft_free_data(map);
				ft_printf("Empty spaces inside map\n");
				return (1);
			}
			i++;
		}
		j++;
	}

	while (map->splited_map[j])
	{
		if (map->splited_map[j][0] == '1' && 
		map->splited_map[j][map->line_width] == '1')
			j++;
		else
		{
			ft_free_data(map);
			ft_printf("MAP not surronded by walls\n");
			return (1);
		}
		if (map->splited_map[0][map->line_width + 1])
		{
			ft_free_data(map);
			ft_printf("Found something that is not a 1\n");
			return (1);
		}
		else if (map->splited_map[0][map->line_width + 1] || 
				map->splited_map[map->height - 1][map->line_width + 1])
		{
			ft_free_data(map);
			ft_printf("Found something that is not a 1\n");
			return (1);
		}
	}
	return (0);
}
