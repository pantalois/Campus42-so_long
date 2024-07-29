/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:26:42 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/29 18:45:50 by loigonza         ###   ########.fr       */
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
		ft_printf("%i\n", map->data->movements);
		map->data->movements++;//hacer iteraciones en la funcion en caso de que el movimiento sea valido.
		ft_move_up(map);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		ft_putchar_fd('A', 1);
		ft_printf("%i\n", map->data->movements);
		map->data->movements++;
		ft_move_down(map);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		ft_putchar_fd('S', 1);
		ft_printf("%i\n", map->data->movements);
		map->data->movements++;
		ft_move_left(map);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		ft_putchar_fd('D', 1);
		ft_printf("%i\n", map->data->movements);
		map->data->movements++;
		ft_move_right(map);
	}
}

void	ft_move_up(t_map *map)
{
	if (map->splited_map[map->data->pos_y_player - 1][map->data->pos_x_player] != 1)
	{	
		ft_printf("pos_x_player = %i\n", map->data->pos_x_player);
		ft_printf("pos_y_player = %i\n", map->data->pos_y_player);
		//map->splited_map[map->data->pos_x_player][map->data->pos_y_player + 1] = 'P';
		ft_printf("%c\n", map->splited_map[map->data->pos_y_player][map->data->pos_x_player]);
		map->splited_map[map->data->pos_y_player][map->data->pos_x_player] = '0';
		map->data->pos_y_player = map->data->pos_y_player - 1;
		map->splited_map[map->data->pos_y_player][map->data->pos_x_player] = 'P';
		ft_printf("%c\n", map->splited_map[map->data->pos_y_player][map->data->pos_x_player]);
		print_map(map);
	}
}

void	ft_move_down(t_map *map)
{
	map = 0;
}

void	ft_move_left(t_map *map)
{
	map = 0;
}

void	ft_move_right(t_map *map)
{
	map = 0;
}
