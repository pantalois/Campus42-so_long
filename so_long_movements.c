/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:26:42 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/31 17:14:31 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		ft_putchar_fd('W', 1);
		
		map->data->movements++;//hacer iteraciones en la funcion en caso de que el movimiento sea valido.
		ft_printf("deu\n");
		ft_move_up(map);
		ft_printf("asdsdfdfg\n");
		return ;
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		ft_putchar_fd('A', 1);
		ft_printf("%i\n", map->data->movements);
		map->data->movements++;
		ft_move_left(map);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		ft_putchar_fd('S', 1);
		ft_printf("%i\n", map->data->movements);
		map->data->movements++;
		ft_move_down(map);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		ft_putchar_fd('D', 1);
		ft_printf("%i\n", map->data->movements);
		map->data->movements++;
		ft_move_right(map);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		
		ft_printf("Escape");
		ft_free_images(map);
	}
}

void	ft_move_up(t_map *map)
{
	if (map->splited_map[map->data->pos_y_plyr - 1][map->data->pos_x_plyr] \
			!= '1')
	{	
		ft_printf("segfault?\n");
		mlx_delete_image(map->d_mlx.mlx, map->d_mlx.plyr_img);
		ft_printf("no_segfault\n");
		map->d_mlx.plyr_img = mlx_texture_to_image(map->d_mlx.mlx, \
				map->d_mlx.plyr);

		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = '0';
		map->data->pos_y_plyr = map->data->pos_y_plyr - 1;	
		if (map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] \
				== 'C')
			ft_destroy_cltb(map);	
		if (map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] \
				== 'E' &&  map->data->amount_cltbl == 0)
		{
			mlx_delete_image(map->d_mlx.mlx, map->d_mlx.o_ex_img);
			map->data->amount_exit--;
			ft_free_images(map);
		}
		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = 'P';

		ft_put_player(map);
		ft_printf("%i\n", map->data->movements);
		print_map(map);
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
				== 'E' &&  map->data->amount_cltbl == 0)
		{
			mlx_delete_image(map->d_mlx.mlx, map->d_mlx.o_ex_img);
			map->data->amount_exit--;
			ft_free_images(map);
			//mlx_delete_xpm42(map->d_mlx->mlx);
		}
		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = 'P';

		ft_put_player(map);
		ft_printf("%i\n", map->data->movements);
		print_map(map);
		
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
				== 'E' &&  map->data->amount_cltbl == 0)
		{
			mlx_delete_image(map->d_mlx.mlx, map->d_mlx.o_ex_img);
			map->data->amount_exit--;
			ft_free_images(map);
		}
		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = 'P';



		ft_put_player(map);
		ft_printf("%i\n", map->data->movements);
		print_map(map);
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
				== 'E' &&  map->data->amount_cltbl == 0)
		{
			mlx_delete_image(map->d_mlx.mlx, map->d_mlx.o_ex_img);
			map->data->amount_exit--;
			ft_free_images(map);
		}
		map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = 'P';



		ft_put_player(map);
		ft_printf("%i\n", map->data->movements);
		print_map(map);
	}
}
