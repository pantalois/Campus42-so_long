/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_flood_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:29:05 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/24 19:48:11 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_flood_fill(t_map *map, int x, int y)
{
    if (x >= map->width || x < 0 || y >= map->height || y < 0 ||
    map->cpy_splited_map[x][y] == '1' || map->cpy_splited_map[x][y] == 'F')
        return ;
    if (map->cpy_splited_map[x][y] == 'C')
        map->data->cpy_amount_cltbl++;
    else if (map->cpy_splited_map[x][y] == 'E')
        map->data->cpy_amount_exit++;
    map->cpy_splited_map[x][y] = 'F';
    ft_flood_fill(map, x + 1, y);
    ft_flood_fill(map, x - 1, y);
    ft_flood_fill(map, x, y + 1);
    ft_flood_fill(map, x, y - 1);
}

int ft_equal_cltbl(t_map *map)
{
    if (map->data->amount_cltbl == map->data->cpy_amount_cltbl)
        return (0);
    else
    {
        ft_printf("Can't access to all de collectionables\n");
        ft_free_data(map);
        return (1);
    }
}