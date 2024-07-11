/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:49:24 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/11 15:39:24 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_type(char *argv)
{
	char *type;

	type = ft_strrchr(argv, '.');
	if (!ft_strncmp(type, ".ber", ft_strlen(type)))
		return (1);
	
	else
		return (0);
}

char *ft_check_map(char *argv)
{
	int	fd;
	t_map	map;	
	int	i;
	int j;
	int	x;

	i = 0;
	j = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	map.line = get_next_line(fd);
	if (!map.line)
	{
		ft_printf("Error, no map inside .ber");//perror?strerror?
		return (0);
	}
	if (ft_check_walls(map, j))
	{
		ft_printf("Map not surrounded by walls\n");
		return (0);
	}
	while (map.line[i]) //aqui calculo la longitud de la primera linea del mapa
		i++;
	while (map.line)
	{	
		x = 0;
		map.line = get_next_line(fd);
		while (map.line && map.line[x])
			x++;
		if (map.line && x == i) //aqui voy comprobando que sean todas iguakes a la primera
			j++;
		else if (map.line && x != i) //aqui compruebo la diferencia meintras exista linea, sino me entra como x = 0
		{
			ft_printf("x = %i\ni = %i\n", x, i);
			ft_printf("Error, map with variable width");//perror?strerror?
			return (0);
		}
	}
	map.width = i - 1;
	map.height = j + 1; //+1 porque antes no tenemos en cuenta la primera fila cuando empezamos el ckeckeo.
	ft_printf("largo = %i\n", map.width);
	ft_printf("ancho = %i\n", map.height);
	//toca decirle a todo esto lo siguiente: que si map.width y map.height son iguales error por mapa cuadrado 
	//ir comprobado que la primera linea del mapa sean todo 1, que la ultima tambien
	//y que todas tengan un 1 y un 1 al principio y al final
	return (0);
}

int ft_check_walls(t_map map, int j)
{
	if (j == 0)
	{	
		while (map.line[j] && map.line[j] == '1')
		{
			ft_printf("%i map.line = %c\n", j, map.line[1]); 
			j++;
		}
		ft_printf("map.line final = %c\n", map.line[j]);
		if (!map.line[j])
			return (1);
		else
			return (0);
	}
	return (0);
}
