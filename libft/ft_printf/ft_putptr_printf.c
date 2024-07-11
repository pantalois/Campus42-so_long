/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:20:32 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/15 12:17:37 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <limits.h>

static int	ft_len_putptr(unsigned long c)
{
	int	lenth;

	lenth = 0;
	if (c == 0)
		lenth++;
	while (c != 0)
	{
		c = c / 16;
		lenth++;
	}
	lenth = lenth + 2;
	return (lenth);
}

static int	ft_write_ptr(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (write (1, &str[i], 1) == -1)
			return (-1);
		i++;
		count++;
	}
	return (count);
}

static char	*ft_ul_to_hex(char *str, int i, unsigned long c)
{
	str[i] = '\0';
	while (c)
	{
		if (((c % 16) >= 10) && ((c % 16) <= 15))
		{
			str[--i] = ((c % 16) - 10) + 'a';
			c = c / 16;
		}
		else if (((c % 16) >= 0) && ((c % 16) <= 9))
		{
			str[--i] = (c % 16) + '0';
			c = c / 16;
		}
	}
	str[1] = 'x';
	str[0] = '0';
	return (str);
}

int	ft_putptr_printf(unsigned long c)
{
	int		i;
	char	*str;
	int		count;

	if (c == 0)
		return (write(1, "0x0", 3));
	count = 0;
	i = ft_len_putptr(c);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (-1);
	str = ft_ul_to_hex(str, i, c);
	count = ft_write_ptr(str);
	free(str);
	return (count);
}
/*
int	main(void)
{
	ft_putptr_printf("%d",5);
	printf("\n");
	printf("%d",5);
	return (0);
}
*/
