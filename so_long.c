/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:47:12 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/25 15:04:45 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	*map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	//crear una funcion que inicialice las estructuras.
	map = (t_map *)malloc(sizeof(t_map));
	//Gestionar fallo de malloc
	ft_memset(map, 0, sizeof(t_map));
	map->data = (t_data_map *)malloc(sizeof(t_data_map));
	//Gestionar fallo malloc
    ft_memset(map->data, 0, sizeof(t_data_map));
	if (argc > 2 || argc < 2)
	{
		ft_printf("Wrong number of arguments\n");
		ft_free_data(map);
		return (0);
	}
	else
	{
		if (ft_map_type(argv[1]))
		{
			if (ft_size_map(argv[1], map) == 1)
				return (1);
			if (ft_split_map(argv[1], map) == 1)
				return (1);
			if (ft_corners_map(map) == 1)
				return (1);	
			if (ft_sides_map(map) == 1)
				return (1);
			if (ft_check_player(map) == 1) //guardar en struct su pos
				return (1);
			if (ft_check_exit(map) == 1)//guardar en struct su pos	
				return (1);
			if (ft_check_cltbl(map) == 1)//guardar en struct el numero de
				return (1);
			x = map->data->pos_x_player;
			y = map->data->pos_y_player;
			ft_flood_fill(map, x, y);
			if (ft_equal_cltbl(map) == 1)
				return (1);
		print_map(map);
		}
		
	}
	ft_free_data(map);
	return (0);
}