/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:47:12 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/09 18:04:03 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	main(int argc, char *argv[])
{
	/*void	*mlx;
	void	*mlx_window;
	t_data	img;*/
	
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
			ft_check_map(argv[1]);
			return (0);
		}
		//si el argumento es un .ber hacer cosas
		//si no lo es que pasa??
	}
/*
	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_window = mlx_new_window(mlx, 1920, 1080, "mapa test");
	mlx_loop(mlx);
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	return (0);
*/
	return (0);
}
