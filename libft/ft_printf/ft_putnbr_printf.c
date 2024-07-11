/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:06:52 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/15 16:58:24 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <limits.h>

int	ft_putnbr_printf(int c)
{
	int	count;

	count = 0;
	if (c == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (c < 0 && ++count)
	{
		if (ft_putchar_printf('-') == -1)
			return (-1);
		c = -c;
	}
	if (c > 9)
	{
		count += ft_putnbr_printf(c / 10);
		if (count == -1)
			return (-1);
		c = c % 10;
	}
	if (c <= 9)
	{
		if (ft_putchar_printf(c + '0') == -1)
			return (-1);
		count++;
	}
	return (count);
}
/*
int	main(void)

{
	int	count;
	int max = 214748;
//	int	nb = 33;
	count = ft_printf(" %i %i", max, 45);
	printf("\n");
	printf("%d\n", count);
	int	count2;
	count2 = printf(" %i %i", max, 45);
	printf("\n");
	printf("%d\n", count2);
int	main(void)
{
	int mio = ft_printf(" %d %d %d %d\n", INT_MAX, INT_MIN, 0, -42);
	printf("\n");
	int org = printf(" %d %d %d %d\n", INT_MAX, INT_MIN, 0, -42);
	printf("\n");
	printf("mio %d, original %d", mio, org);
	return (0);
}
*/
