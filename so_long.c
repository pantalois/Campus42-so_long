/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:47:12 by loigonza          #+#    #+#             */
/*   Updated: 2024/08/02 16:39:59 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_start(t_map *map)
{
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

int	ft_lets_check_map(t_map *map, char **argv)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if ((ft_map_type(argv[1]) || ft_size_map(argv[1], map)
			|| ft_split_map(argv[1], map) || ft_random_char(map)
			|| ft_sides_map(map) || ft_corners_map(map) || ft_check_player(map)
			|| ft_check_exit(map) || ft_check_cltbl(map)
			|| ft_checker_map(map) || ft_white_spaces(map)
			|| ft_check_lenght(map)) == 1)
		return (1);
	x = map->data->pos_x_plyr;
	y = map->data->pos_y_plyr;
	ft_flood_fill(map, x, y);
	if (ft_equal_cltbl(map) == 1)
		return (1);
	if (ft_equal_exit(map) == 1)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (1);
	ft_memset(map, 0, sizeof(t_map));
	map->data = (t_data_map *)malloc(sizeof(t_data_map));
	if (!map->data)
	{
		ft_free_data(map);
		return (1);
	}
	ft_memset(map->data, 0, sizeof(t_data_map));
	if (argc != 2)
		return (ft_write_error(ERRORARGV), ft_free_data(map), 1);
	else
	{
		if (ft_lets_check_map(map, argv) == 1)
			exit(1);
	}
	ft_mlx_start(map);
	ft_free_images(map);
	ft_free_data(map);
	return (0);
}
