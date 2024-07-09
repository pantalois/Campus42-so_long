/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:21:19 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/09 17:59:16 by loigonza         ###   ########.fr       */
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
char	*ft_check_map(char *argv);

#endif
