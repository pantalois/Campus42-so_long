/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:51:21 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/18 12:38:45 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	chr;
	char	*str;

	i = 0;
	chr = (char)c;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return (&str[i]);
		else
			i++;
	}
	if (chr == '\0')
		return (&str[i]);
	else
		return (0);
}

char	*ft_strchr_not_found(const char *s, int c)
{
	int		i;
	char	chr;
	char	*str;

	i = 0;
	chr = (char)c;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] != chr)
			return (&str[i]);
		else
			i++;
	}
	if (chr == '\0')
		return (&str[i]);
	else
		return (0);
}
/*
int	main(void)
{
	char	*s = "xswerfdgtfvPccc";
	int	c = 'w';
	printf("encontro: %s\n", ft_strchr(s, c));
	printf("funcion: %s\n", strchr(s, c));
	return (0);
}
*/
