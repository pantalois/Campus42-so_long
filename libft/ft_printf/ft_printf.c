/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:23:01 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/15 13:26:24 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_check(const char format, int count, va_list args)
{
	int	check;

	check = 0;
	if (format == 'c')
		check = ft_putchar_printf(va_arg(args, int));
	else if (format == 's')
		check = ft_putstr_printf(va_arg(args, char *));
	else if (format == 'p')
		check = ft_putptr_printf(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		check = ft_putnbr_printf(va_arg(args, int));
	else if (format == 'u')
		check = ft_putuint_printf(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		check = ft_putulhex_printf(va_arg(args, unsigned int), &format);
	else if (format == '%')
		check = ft_putchar_printf('%');
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	va_start(args, format);
	count = 0;
	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && ++i)
		{
			count = ft_format_check(format[i], count, args);
			if (count == -1)
				return (-1);
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			count++;
		}
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{

	//char	*prueba_str;
	//char const	*str;

	//prueba_str = "holi";
	//str = 
	int d = printf("org %%c\n"); 
	int h = ft_printf("mio %%c\n");
	
	printf("%d, mio %d", d, h);
	printf("\n");
	printf("_%d\n", printf(" %ld %d %d", 4294967295, 0, -42));
}

int	main(void)
{
//	int variable = 42;

	int *ptr = 0;
	printf("\n%d\n", ft_printf(" %p %p", ptr, ptr));
	printf("\n%d\n", printf(" %p %p ", ptr, ptr));
	return (0);
}	
*/
