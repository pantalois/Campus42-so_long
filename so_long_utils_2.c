/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:34:41 by loigonza          #+#    #+#             */
/*   Updated: 2024/08/02 16:40:45 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_corners_map(t_map *map)
{
	char	*check;

	if (map->splited_map[map->height - 1] \
		&& !ft_strncmp(map->splited_map[0], map->splited_map[map->height - 1], \
		ft_strlen(map->splited_map[0])))
	{
		check = ft_strchr_not_found(map->splited_map[0], '1');
		if (check)
		{
			ft_write_error(ERROR1);
			return (ft_free_data(map), 1);
		}
	}
	else if (!map->splited_map[map->height - 1])
	{
		ft_write_error(ERROREMPTY);
		return (ft_free_data(map), 1);
	}
	else
	{
		ft_write_error(ERRORLIMITS);
		return (ft_free_data(map), 1);
	}
	return (0);
}

int	ft_sides_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->splited_map[j][i])
		i++;
	map->first_line_width = i - 1;
	i = 0;
	j++;
	while (map->splited_map[j][i])
	{
		i = 0;
		while (map->splited_map[j][i])
			i++;
		map->line_width = i - 1;
		if (i >= 39)
			return (ft_write_error(ERRORLIMITS2), ft_free_data(map), 1);
		if (map->height >= 22)
			return (ft_write_error(ERRORLIMITS2), ft_free_data(map), 1);
		if (map->first_line_width != map->line_width)
			return (ft_write_error(ERRORLIMITS3), ft_free_data(map), 1);
		j++;
	}
	return (0);
}

int	ft_white_spaces(t_map *map)
{
	int	j;
	int	i;

	j = 0;
	while (map->splited_map[j])
	{
		i = 0;
		while (map->splited_map[j][i])
		{
			if ((map->splited_map[j][i] >= 9 && map->splited_map[j][i] <= 13) \
					|| map->splited_map[j][i] == 32)
				return (ft_write_error(ERROREMPTY2), ft_free_data(map), 1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_checker_map(t_map *map)
{
	int	j;

	j = 0;
	while (map->splited_map[j])
	{
		if (map->splited_map[j][0] == '1'
			&& map->splited_map[j][map->line_width] == '1')
			j++;
		else
			return (ft_write_error(ERRORLIMITS4), ft_free_data(map), 1);
		if (map->splited_map[0][map->line_width + 1])
			return (ft_write_error(ERROR1), ft_free_data(map), 1);
		else if (map->splited_map[0][map->line_width + 1] ||
			map->splited_map[map->height - 1][map->line_width + 1])
			return (ft_write_error(ERROR1), ft_free_data(map), 1);
	}
	return (0);
}

int	ft_check_lenght(t_map *map)
{
	int	j;
	int	i;

	j = 0;
	while (map->splited_map[j])
	{
		i = 0;
		while (map->splited_map[j][i])
			i++;
		if (map->first_line_width != i - 1)
			return (ft_write_error(ERRORLIMITS3), ft_free_data(map), 1);
		j++;
	}
	return (0);
}
