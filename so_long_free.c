/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:13:21 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/24 16:38:01 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_free_data(t_map *map)
{
    if (map)
    {
        if (map->line)
            free(map->line);
        if (map->splited_map)
            ft_free_splited_data(map);
        free(map->data);
        free(map);
    }
}

void    ft_free_splited_data(t_map *map)
{
    int i;

    i = 0;
    if (map->splited_map)
    {
        while (map->splited_map[i])
        {
            free(map->splited_map[i]);
            i++;
        }
        free(map->splited_map);
    }
}
