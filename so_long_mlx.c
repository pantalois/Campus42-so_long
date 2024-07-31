/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:55:55 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/31 16:34:17 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_images(t_map *map)
{
	map->d_mlx.flor = mlx_load_png("so_long_PNG/Floor.png");
	map->d_mlx.wall = mlx_load_png("so_long_PNG/Wall.png");
	map->d_mlx.plyr = mlx_load_png("so_long_PNG/Player.png");
	map->d_mlx.cltb = mlx_load_png("so_long_PNG/cltbl.png");
	map->d_mlx.c_ex = mlx_load_png("so_long_PNG/closed_exit.png");
	map->d_mlx.o_ex = mlx_load_png("so_long_PNG/open_exit.png");
	map->d_mlx.flor_img = mlx_texture_to_image(map->d_mlx.mlx, map->d_mlx.flor);
	map->d_mlx.wall_img = mlx_texture_to_image(map->d_mlx.mlx, map->d_mlx.wall);
	map->d_mlx.plyr_img = mlx_texture_to_image(map->d_mlx.mlx, map->d_mlx.plyr);
	map->d_mlx.cltb_img = mlx_texture_to_image(map->d_mlx.mlx, map->d_mlx.cltb);
	map->d_mlx.c_ex_img = mlx_texture_to_image(map->d_mlx.mlx, map->d_mlx.c_ex);
	map->d_mlx.o_ex_img = mlx_texture_to_image(map->d_mlx.mlx, map->d_mlx.o_ex);
	if (!map->d_mlx.flor_img || ! map->d_mlx.wall_img || !map->d_mlx.plyr_img
		|| !map->d_mlx.cltb_img || ! map->d_mlx.c_ex_img
		|| !map->d_mlx.o_ex_img)
		return (1);
	return (0);
}

void	ft_put_floor(t_map *map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (map->splited_map[j])
	{
		while (map->splited_map[j][i])
		{
			mlx_resize_image(map->d_mlx.flor_img, 50, 50);
			mlx_image_to_window(map->d_mlx.mlx, map->d_mlx.flor_img, x, y);
			i++;
			x += 50;
		}
		j++;
		x = 0;
		i = 0;
		y += 50;
	}
}

void	ft_put_wall(t_map *map)
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
			if (map->splited_map[j][i] == '1' && map->splited_map[j][i])
			{
				mlx_resize_image(map->d_mlx.wall_img, 50, 50);
				mlx_image_to_window(map->d_mlx.mlx, map->d_mlx.wall_img, x, y);
			}
			i++;
			x += 50;
		}
		x = 0;
		i = 0;
		y += 50;
	}
}

void	ft_put_cltbl(t_map *map)
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
			if (map->splited_map[j][i] == 'C' && map->splited_map[j][i])
			{
				mlx_resize_image(map->d_mlx.cltb_img, 40, 40);
				mlx_image_to_window(map->d_mlx.mlx, map->d_mlx.cltb_img, x, y);
			}
			i++;
			x += 50;
		}
		x = 0;
		i = 0;
		y += 50;
	}
}

void	ft_put_player(t_map *map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	i = 0;
	j = -1;
	while (map->splited_map[++j])
	{
		x = 0;
		while (map->splited_map[j][i])
		{
			if (map->splited_map[j][i] == 'P' && map->splited_map[j][i])
			{
				mlx_resize_image(map->d_mlx.plyr_img, 50, 50);
				mlx_image_to_window(map->d_mlx.mlx, map->d_mlx.plyr_img, x, y);
			}
			i++;
			x += 50;
		}
		x = 0;
		i = 0;
		y += 50;
	}
}
