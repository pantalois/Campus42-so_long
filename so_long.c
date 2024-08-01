/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:47:12 by loigonza          #+#    #+#             */
/*   Updated: 2024/08/01 12:03:24 by loigonza         ###   ########.fr       */
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
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (1);
	ft_memset(map, 0, sizeof(t_map));
	map->data = (t_data_map *)malloc(sizeof(t_data_map));
	if (!map->data)
		return (1);
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
			if (ft_random_char(map) == 1)
				return (1);
			if (ft_sides_map(map) == 1)
				return (1);
			if (ft_corners_map(map) == 1)
				return (1);
			if (ft_check_player(map) == 1)
				return (1);
			if (ft_check_exit(map) == 1)
				return (1);
			if (ft_check_cltbl(map) == 1)
				return (1);
			x = map->data->pos_x_plyr;
			y = map->data->pos_y_plyr;
			ft_flood_fill(map, x, y);
			if (ft_equal_cltbl(map) == 1)
				return (1);
			if (ft_equal_exit(map) == 1)
				return (1);
			print_map(map);
		}
		map->d_mlx.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
		ft_load_images(map);
		ft_put_floor(map);
		ft_put_wall(map);
		ft_put_player(map);
		ft_put_cltbl(map);
		map->d_mlx.image = mlx_new_image(map->d_mlx.mlx, 200, 200);
		mlx_key_hook(map->d_mlx.mlx, &my_keyhook, map);
		mlx_loop(map->d_mlx.mlx);
		mlx_terminate(map->d_mlx.mlx);
	}
	ft_free_data(map);
	return (0);
}
