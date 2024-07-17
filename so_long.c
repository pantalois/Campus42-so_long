/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:47:12 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/17 19:13:38 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	main(int argc, char *argv[])
{
	/*void	*mlx;
	void	*mlx_window;
	t_data	img;*/
	t_map *map;
	char	**splited_map;

	map = (t_map *)malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(map));
	(void)argv;
	//antes de iniciar la mlx controlar que no me pete nada.
	//solo podre recibir 2 argc, porque sino no podre leer mas de  2 archivos
	if (argc > 2)
	{
		ft_printf("Too much arguments\n");
		return (0);
	}
	else if (argc < 2)
	{
		ft_printf("Not enough arguments\n");
		return (0);
	}
	else
	{
		if (ft_map_type(argv[1]))
		{
			if (ft_size_map(argv[1], map) == 1)
				return (1);
			splited_map = ft_split_map(argv[1], map);
		}
	}

/*	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_window = mlx_new_window(mlx, 1920, 1080, "mapa test");
	mlx_loop(mlx);
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	return (0);
*/
	free(map->line);
	free(map);
	return (0);
}

