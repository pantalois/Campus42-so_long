/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:52:47 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/15 12:05:25 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putuint_printf(unsigned int c)
{
	int	count;

	count = 0;
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
int main(void)
{
	ft_putuint_printf(1230);
	return (0);
}
*/
