/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:21:19 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/18 15:18:29 by loigonza         ###   ########.fr       */
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
#define WIDTH 256
#define HEIGHT 256



int	ft_map_type(char *argv);

//memset a estructura 
typedef struct s_map
{
	int	height;
	int width;
	int	line_width;
	char	*line;
	char	**splited_map;
}	t_map;

int		ft_split_map(char *argv, t_map *map);
int		ft_size_map(char *argv, t_map *map);
int		ft_corners_map(t_map *map);
int		ft_sides_map(t_map *map);
void	ft_free_data(t_map *map);
void	ft_free_splited_data(t_map *map);

//int ft_check_walls(t_map map, int j);
//int	ft_chrsearch(t_map map, char c, int j);
#endif
