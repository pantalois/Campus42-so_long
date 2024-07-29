/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checks_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:42:50 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/24 19:43:11 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int ft_check_player(t_map *map)
{
    while (map->splited_map[map->data->y_player])
    {
        while (map->splited_map[map->data->y_player][map->data->x_player] != 'P'
        && map->splited_map[map->data->y_player][map->data->x_player])
            map->data->x_player++;
        if (map->splited_map[map->data->y_player][map->data->x_player] == 'P')
        {
            map->data->pos_x_player = map->data->x_player;
            map->data->pos_y_player = map->data->y_player;
            map->data->x_player++;
            map->data->amount_player++;
        }
        else
        {
            map->data->y_player++;
            map->data->x_player = 0;
        }
    }
    if (map->data->amount_player == 1)
        return (0);
    else
    {
        ft_printf("Player not setted properly\n");
        return (ft_free_data(map), 1);
    }
}

int     ft_check_exit(t_map *map)
{
    while (map->splited_map[map->data->y_exit])
    {
        while (map->splited_map[map->data->y_exit][map->data->x_exit] != 'E' &&
         map->splited_map[map->data->y_exit][map->data->x_exit])
            map->data->x_exit++;
        if (map->splited_map[map->data->y_exit][map->data->x_exit] == 'E')
        {
            map->data->pos_x_exit = map->data->x_exit;
            map->data->pos_y_exit = map->data->y_exit;
            map->data->x_exit++;
            map->data->amount_exit++;
        }
        else
        {
            map->data->y_exit++;
            map->data->x_exit = 0;
        }
    }
    if (map->data->amount_exit == 1)
        return (0);
    else
    {
        ft_printf("Exit not setted properly\n");   
        return (ft_free_data(map), 1);
    }
}



int     ft_check_cltbl(t_map *map)
{
    while (map->splited_map[map->data->y_cltbl])
    {
        while (map->splited_map[map->data->y_cltbl][map->data->x_cltbl] != 'C' 
        && map->splited_map[map->data->y_cltbl][map->data->x_cltbl])
            map->data->x_cltbl++;
        if (map->splited_map[map->data->y_cltbl][map->data->x_cltbl] == 'C')
        {
            map->data->x_cltbl++;
            map->data->amount_cltbl++;
        }
        else
        {
            map->data->y_cltbl++;
            map->data->x_cltbl = 0;
        }
    }
    if (map->data->amount_cltbl == 0)
    {
        ft_printf("There is not collectables\n");   
        return (ft_free_data(map), 1);
    }
    else
       return (0);
}
