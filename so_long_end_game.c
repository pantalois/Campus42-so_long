/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_end_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:06:39 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/30 17:16:49 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_cltb(t_map *map)
{
	//poner imagen encima de 0 del coltb, una vez la amount sea 0 destroy image
	map->splited_map[map->data->pos_y_plyr][map->data->pos_x_plyr] = '0';
	mlx_delete_image(map->d_mlx.mlx, map->d_mlx.cltb_img);
	map->d_mlx.cltb_img = mlx_texture_to_image(map->d_mlx.mlx, \
				map->d_mlx.cltb);

	ft_put_cltbl(map);
	map->data->amount_cltbl--;
	if (map->data->amount_cltbl  == 0)
	{
		ft_put_exit(map);
	}
}

void	ft_put_exit(t_map *map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	j = -1;
	while (map->splited_map[++j])
	{
		while (map->splited_map[j][i])
		{
			if (map->splited_map[j][i] == 'E' && map->splited_map[j][i])
			{
				mlx_resize_image(map->d_mlx.o_ex_img, 50, 50);
				mlx_image_to_window(map->d_mlx.mlx, map->d_mlx.o_ex_img, x, y);
			}
			else
				map->splited_map[map->data->pos_y_exit][map->data->pos_x_exit] = 'E';
			i++;
			x += 50;
		}
		x = 0;
		i = 0;
		y += 50;
	}
}
