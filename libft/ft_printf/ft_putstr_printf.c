/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:45:39 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/15 12:04:28 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr_printf(char *c)
{
	int	i;

	i = 0;
	if (!c)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (c[i] != '\0')
	{
		if (write(1, &c[i], 1) == -1)
			return (-1);
		else
			i++;
	}
	return (i);
}
