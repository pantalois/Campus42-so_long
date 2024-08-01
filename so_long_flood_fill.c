/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_flood_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:29:05 by loigonza          #+#    #+#             */
/*   Updated: 2024/08/01 13:40:19 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(t_map *map, int x, int y)
{
	if (x >= map->width || x < 0 || y > map->height || y < 0 \
		|| map->cpy_splited_map[y][x] == '1' \
		|| map->cpy_splited_map[y][x] == 'F')
		return ;
	if (map->cpy_splited_map[y][x] == 'C')
		map->data->cpy_amount_cltbl++;
	if (map->cpy_splited_map[y][x] == 'E')
		map->data->cpy_amount_exit++;
	map->cpy_splited_map[y][x] = 'F';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

int	ft_equal_cltbl(t_map *map)
{
	if (map->data->amount_cltbl == map->data->cpy_amount_cltbl)
		return (0);
	else
	{
		ft_printf("Can't access to all the collectionables\n");
		ft_free_data(map);
		return (1);
	}
}

int	ft_equal_exit(t_map *map)
{
	if (map->data->amount_exit == map->data->cpy_amount_exit)
		return (0);
	else
	{
		ft_printf("Can't access to the exit\n");
		ft_free_data(map);
		return (1);
	}
}

int	ft_random_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->splited_map[j])
	{
		i = 0;
		while (map->splited_map[j][i])
		{
			if (map->splited_map[j][i] != 'P' && map->splited_map[j][i] != 'C' \
					&& map->splited_map[j][i] != 'E' \
					&& map->splited_map[j][i] != '0' \
					&& map->splited_map[j][i] != '1' \
					&& map->splited_map[j][i] != '\n')
			{
				ft_free_data(map);
				ft_printf("Weird char found inside the map\n");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
