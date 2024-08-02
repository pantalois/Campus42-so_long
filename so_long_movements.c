/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:26:42 by loigonza          #+#    #+#             */
/*   Updated: 2024/08/02 15:30:34 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_move_up(map);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_move_left(map);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_move_down(map);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_move_right(map);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->d_mlx.mlx);
}

void	ft_move_up(t_map *map)
{
	if (map->splited_map[map->data->pos_y_plyr - 1][map->data->pos_x_plyr] \
			!= '1')
	{
		mlx_delete_image(map->d_mlx.mlx, map->d_mlx.plyr_img);
		map->d_mlx.plyr_img = mlx_texture_to_image(map->d_mlx.mlx, \
				map->d_mlx.plyr);
		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = '0';
		map->data->pos_y_plyr = map->data->pos_y_plyr - 1;
		if (map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] \
				== 'C')
			ft_destroy_cltb(map);
		if (map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] \
				== 'E' && map->data->amount_cltbl == 0)
		{
			mlx_delete_image(map->d_mlx.mlx, map->d_mlx.o_ex_img);
			map->data->amount_exit--;
			mlx_close_window(map->d_mlx.mlx);
		}
		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = 'P';
		ft_put_player(map);
		map->data->movements++;
		ft_printf("Player movements = %i\n", map->data->movements);
	}
}

void	ft_move_down(t_map *map)
{
	if (map->splited_map[map->data->pos_y_plyr + 1][map->data->pos_x_plyr] \
			!= '1')
	{
		mlx_delete_image(map->d_mlx.mlx, map->d_mlx.plyr_img);
		map->d_mlx.plyr_img = mlx_texture_to_image(map->d_mlx.mlx, \
				map->d_mlx.plyr);
		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = '0';
		map->data->pos_y_plyr = map->data->pos_y_plyr + 1;
		if (map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] \
				== 'C')
			ft_destroy_cltb(map);
		if (map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] \
				== 'E' && map->data->amount_cltbl == 0)
		{
			mlx_delete_image(map->d_mlx.mlx, map->d_mlx.o_ex_img);
			map->data->amount_exit--;
			mlx_close_window(map->d_mlx.mlx);
		}
		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = 'P';
		ft_put_player(map);
		map->data->movements++;
		ft_printf("Player movements = %i\n", map->data->movements);
	}
}

void	ft_move_left(t_map *map)
{
	if (map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr - 1] \
			!= '1')
	{
		mlx_delete_image(map->d_mlx.mlx, map->d_mlx.plyr_img);
		map->d_mlx.plyr_img = mlx_texture_to_image(map->d_mlx.mlx, \
				map->d_mlx.plyr);
		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = '0';
		map->data->pos_x_plyr = map->data->pos_x_plyr - 1;
		if (map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] \
				== 'C')
			ft_destroy_cltb(map);
		if (map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] \
				== 'E' && map->data->amount_cltbl == 0)
		{
			mlx_delete_image(map->d_mlx.mlx, map->d_mlx.o_ex_img);
			map->data->amount_exit--;
			mlx_close_window(map->d_mlx.mlx);
		}
		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = 'P';
		ft_put_player(map);
		map->data->movements++;
		ft_printf("Player movements = %i\n", map->data->movements);
	}
}

void	ft_move_right(t_map *map)
{
	if (map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr + 1] \
			!= '1')
	{
		mlx_delete_image(map->d_mlx.mlx, map->d_mlx.plyr_img);
		map->d_mlx.plyr_img = mlx_texture_to_image(map->d_mlx.mlx, \
				map->d_mlx.plyr);
		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = '0';
		map->data->pos_x_plyr = map->data->pos_x_plyr + 1;
		if (map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] \
				== 'C')
			ft_destroy_cltb(map);
		if (map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] \
				== 'E' && map->data->amount_cltbl == 0)
		{
			mlx_delete_image(map->d_mlx.mlx, map->d_mlx.o_ex_img);
			map->data->amount_exit--;
			mlx_close_window(map->d_mlx.mlx);
		}
		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = 'P';
		ft_put_player(map);
		map->data->movements++;
		ft_printf("Player movements = %i\n", map->data->movements);
	}
}
