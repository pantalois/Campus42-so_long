/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:47:12 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/18 14:57:00 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(map));
	
	if (argc > 2 || argc < 2)
	{
		ft_printf("Wrong number of arguments\n");
		ft_free_data(map);
		return (0);
	}
	else
	{
		if (ft_map_type(argv[1]))
		{
			if (ft_size_map(argv[1], map) == 1)
				return (1);
			if (ft_split_map(argv[1], map) == 1)
				return (1);
			if (ft_corners_map(map) == 1)
				return (1);	
			if (ft_sides_map(map) == 1)
				return (1);
		}
	}
	ft_free_data(map);
	return (0);
}

