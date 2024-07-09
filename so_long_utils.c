/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:49:24 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/09 18:28:50 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_type(char *argv)
{
	char *type;

	type = ft_strrchr(argv, '.');
	ft_printf("tipo %s\n", type);
	if (!ft_strncmp(type, ".ber", ft_strlen(type)))
		return (1);
	else
		return (0);
}

char *ft_check_map(char *argv)
{
	int	fd;
	char *line;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	return (0);
}
