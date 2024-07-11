/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulhex_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:32:27 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/15 13:21:28 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_len_putulhex(unsigned long c)
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
	lenth = lenth + 1;
	return (lenth);
}

static int	ft_write_hex(char *str, int i)
{
	int	count;

	count = 0;
	while (str[i] != '\0')
	{
		if (write (1, &str[i], 1) == -1)
			return (-1);
		i++;
		count++;
	}
	str[i] = '\0';
	return (count);
}

static char	*ft_dectohex(int i, const char *format, char *str, unsigned long c)
{
	str[--i] = '\0';
	while (i && c != 0)
	{
		if (((c % 16) >= 10) && ((c % 16) <= 15))
		{
			if (*format == 'x')
				str[--i] = ((c % 16) - 10) + 'a';
			else if (*format == 'X')
				str[--i] = ((c % 16) - 10) + 'A';
			c = c / 16;
		}
		else if (((c % 16) >= 0) && ((c % 16) <= 9))
		{
			str[--i] = (c % 16) + '0';
			c = c / 16;
		}
	}
	return (str);
}

int	ft_putulhex_printf(unsigned int c, const char *format)
{
	int		i;
	char	*str;
	int		count;

	if (c == 0)
		return (write(1, "0", 1));
	count = 0;
	i = ft_len_putulhex(c);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (-1);
	str = ft_dectohex(i, format, str, c);
	i = 0;
	while (str[i] == 0)
		i++;
	count = ft_write_hex(str, i);
	free(str);
	return (count);
}
/*
int	main(void)
{
	const char *b = "X";
	unsigned long a = -10;
	printf("%d\n", ft_putulhex_printf(a, b));
	printf("\n");
	printf("%d\n", printf("%X", -10));
	return (0);
}
*/
