/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:49:15 by loigonza          #+#    #+#             */
/*   Updated: 2024/08/02 16:19:49 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define WIDTH 1920
# define HEIGHT 1080
# define ERRORARGV "Error\nWrong number of arguments\n"
# define ERRORSQUARE "Error\nSquared map\n"
# define ERRORBER	"Error\nNot .ber\n"
# define ERRORFD	"Error\nFailed apening map\n"
# define ERROR1		"Error\nFound something that is not a 1\n"
# define ERROREMPTY "Error\nEmpty line on map\n"
# define ERROREMPTY2 "Error\nEmpty spaces inside map\n"
# define ERRORLIMITS "Error\nTop and below limits can not differ\n"
# define ERRORLIMITS2 "Error\nMap out of the window limits\n"
# define ERRORLIMITS3 "Error\nAll the sides of the map are not equal\n"
# define ERRORLIMITS4 "Error\nMap not surronded by walls\n"
# define ERRORP "Error\nPlayer not setted properly\n"
# define ERRORE "Error\nExit not setted properly\n"
# define ERRORE2 "Error\nCan't access to the exit\n"
# define ERRORC "Error\nThere is not collectables\n"
# define ERRORC2 "Error\nCan't access to all the collectionables\n"
# define ERRORCHAR "Error\nWeird char found inside the map\n"

typedef struct s_data_map
{
	int	x_player;
	int	y_player;
	int	amount_player;
	int	pos_x_plyr;
	int	pos_y_plyr;
	int	x_exit;
	int	y_exit;
	int	amount_exit;
	int	cpy_amount_exit;
	int	ps_x_ex;
	int	ps_y_ex;
	int	x_cltbl;
	int	y_cltbl;
	int	amount_cltbl;
	int	cpy_amount_cltbl;
	int	movements;
}	t_data_map;

typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_texture_t	*flor;
	mlx_texture_t	*wall;
	mlx_texture_t	*plyr;
	mlx_texture_t	*cltb;
	mlx_texture_t	*c_ex;
	mlx_texture_t	*o_ex;
	mlx_image_t		*flor_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*plyr_img;
	mlx_image_t		*cltb_img;
	mlx_image_t		*c_ex_img;
	mlx_image_t		*o_ex_img;
}	t_mlx;

typedef struct s_map
{
	int			height;
	int			width;
	int			first_line_width;
	int			line_width;
	char		*line;
	char		**splited_map;
	char		**cpy_splited_map;
	t_data_map	*data;
	t_mlx		d_mlx;
}	t_map;

int		ft_map_type(char *argv);
int		ft_split_map(char *argv, t_map *map);
int		ft_size_map(char *argv, t_map *map);
int		ft_corners_map(t_map *map);
int		ft_sides_map(t_map *map);
void	ft_free_data(t_map *map);
void	ft_free_splited_data(t_map *map);
int		ft_check_player(t_map *map);
int		ft_check_exit(t_map *map);
int		ft_check_cltbl(t_map *map);
void	ft_flood_fill(t_map *map, int x, int y);
int		ft_equal_cltbl(t_map *map);
int		ft_equal_exit(t_map *map);
int		ft_random_char(t_map *map);
int		ft_load_images(t_map *map);
void	ft_put_wall(t_map *map);
void	ft_put_floor(t_map *map);
void	ft_put_cltbl(t_map *map);
void	ft_put_player(t_map *map);
void	ft_put_exit(t_map *map);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	ft_move_up(t_map *map);
void	ft_move_down(t_map *map);
void	ft_move_left(t_map *map);
void	ft_move_right(t_map *map);
void	ft_destroy_cltb(t_map *map);
void	ft_free_images(t_map *map);
int		ft_check_squared(t_map *map);
int		ft_get_the_line(t_map *map, char *line, int fd);
int		ft_white_spaces(t_map *map);
int		ft_checker_map2(t_map *map);
void	ft_resize_exit(t_map *map, int x, int y);
void	ft_write_error(char *error);
int		ft_lets_check_map(t_map *map, char **argv);
void	ft_mlx_start(t_map *map);
int		ft_checker_map(t_map *map);
int		ft_white_spaces(t_map *map);
int		ft_check_lenght(t_map *map);

#endif
