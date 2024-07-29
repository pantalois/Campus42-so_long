/* ************************************************************************** */
/*																			  */	
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:21:19 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/29 12:16:07 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

#include "MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define WIDTH 1920
#define HEIGHT 1080



int	ft_map_type(char *argv);

//memset a estructura 

typedef struct s_data_map
{
	int x_player;
	int y_player;
	int	amount_player;
	int pos_x_player;
	int pos_y_player;
	int	x_exit; 
	int	y_exit;
	int	amount_exit;
	int	cpy_amount_exit;
	int	pos_x_exit;
	int	pos_y_exit;
	int	x_cltbl;
	int	y_cltbl;
	int amount_cltbl;
	int	cpy_amount_cltbl;
	int	movements;
}	t_data_map;

typedef	struct s_mlx
{
	mlx_t	*mlx;
	mlx_image_t	*image;
	mlx_texture_t *flor;
	mlx_texture_t *wall;
	mlx_texture_t *plyr;
	mlx_texture_t *cltb;
	mlx_texture_t *c_ex;
	mlx_texture_t *o_ex;
	mlx_image_t *flor_img;
	mlx_image_t *wall_img;
	mlx_image_t *plyr_img;
	mlx_image_t *cltb_img;
	mlx_image_t *c_ex_img;
	mlx_image_t *o_ex_img;
}	t_mlx;

typedef struct s_map
{
	int	height;
	int width;
	int	line_width;
	char	*line;
	char	**splited_map;
	char	**cpy_splited_map;
	t_data_map *data;
	t_mlx	d_mlx;
}	t_map;




int		ft_split_map(char *argv, t_map *map);
int		ft_size_map(char *argv, t_map *map);
int		ft_corners_map(t_map *map);
int		ft_sides_map(t_map *map);
void	ft_free_data(t_map *map);
void	ft_free_splited_data(t_map *map);
int		ft_check_player(t_map *map);
int		ft_check_exit(t_map *map);
int     ft_check_cltbl(t_map *map);
void	ft_flood_fill(t_map *map, int x, int y);
int 	ft_equal_cltbl(t_map *map);
void    print_map(t_map *map);
int		ft_load_images(t_map *map);
void	ft_put_wall(t_map *map);
void	ft_put_floor(t_map *map);
void	ft_put_cltbl(t_map *map);
void	ft_put_player(t_map *map);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	ft_move_up(t_map* map);
void	ft_move_down(t_map* map);
void	ft_move_left(t_map* map);
void	ft_move_right(t_map* map);


#endif
