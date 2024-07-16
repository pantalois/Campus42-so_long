/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:49:24 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/16 12:08:25 by loigonza         ###   ########.fr       */
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

	//checkear que dentro del mapa solo sea 1, 0, p, c, e
	j = 1;
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
	 //aqui calculo la longitud de la primera linea del mapa
	//ft_printf("mi i es = %i\n", i);
	while (map.line)
	{	
		x = 0;
		i = ft_strlen(map.line);
		if ((map.line = get_next_line(fd)) == NULL)
			return (NULL);
		if (map.line)
			x = ft_strlen(map.line);
		if (map.line && ft_strchr(map.line, '\n'))//si encuentro salto de linea le bajo 1 a x e i
		{
			x--;
			i--;
		}
		else
			i--;//si no encuentro salto de linea solo le bajo a i
		if (map.line && x == i) //aqui voy comprobando que sean todas iguakes a la primera
			j++;
		else if (map.line && x != i) //aqui compruebo la diferencia meintras exista linea, sino me entra como x = 0. el x + 1 es porque el i viene con uno anhadido de salto de linea
		{
			ft_printf("Error, map with variable width");//perror?strerror?
			return (0);
		}
		map.width = i + 1; //+1 por el tema del salto de linea final que he ido quitando
		map.height = j; //sin +1 porque antes tenemos en cuenta la primera fila cuando declaramos la j.
		if (ft_check_walls(map, j))
		{
			ft_printf("Map not surro walls\n");
			return (0);
		}
	}
	/*
	if (ft_check_walls(map, j))
		{
			ft_printf("Map not surro walls\n");
			return (0);
		}
	ft_printf("ancho = %i\n", map.width);
	ft_printf("alto = %i\n", map.height);
	//toca decirle a todo esto lo siguiente: que si map.width y map.height son iguales error por mapa cuadrado 
	//ir comprobado que la primera linea del mapa sean todo 1, que la ultima tambien
	//y que todas tengan un 1 y un 1 al principio y al final*/
	return (0);
}

int ft_check_walls(t_map map, int j)
{
	if (map.line)
	{
		ft_printf("mi valor j es = %i\n", j);
		if (ft_chrsearch(map, '1', j))
		{
			ft_printf("hola manin\n");
			return (0);
		}
		else
		{
			ft_printf("vamos a ver\n");
			return (1);
		}
	}
	return (0);
}

int	ft_chrsearch(t_map map, char c, int j)
{
	int	i;

	i = 0;
	ft_printf("mi valor de map_height = %d\n", map.height);
	if (j == 1)
	{
		while (map.line[i] && map.line[i] != '\n' && map.line[i] == c)
			i++;
		if (map.line[i] == '\n')
			return (1);
		else
			return (0);
	}
	else if (j != 0)
	{
		if (map.line[0] == c && map.line[ft_strlen(map.line) - 2] == c)
			return (1);
		else
			return (0);
	}
	else if (j == map.height)
	{
		while (map.line[i] && map.line[i] != '\n' && map.line[i] == c)
			i++;
		if (map.line[i] == '\n')
			return (1);
		else
			return (0);
	}
	return (0);
}
