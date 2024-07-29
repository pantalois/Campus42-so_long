/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:47:49 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/25 14:53:40 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_map(t_map *map)
{
    int i = 0;
    int j = 0;

    while (map->splited_map[i])
    {
        j = 0;
        while (map->splited_map[i][j])
        {
            ft_printf("%c", map->splited_map[i][j]);
            j++;
        }
        i++;
        ft_printf("\n");
    }
    i = 0;
    j = 0;
    ft_printf("----------\n");
    while (map->cpy_splited_map[i])
    {
        j = 0;
        while (map->cpy_splited_map[i][j])
        {
            ft_printf("%c", map->cpy_splited_map[i][j]);
            j++;
        }
        i++;
        ft_printf("\n");
    }   
}
