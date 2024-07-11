/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:17:26 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/15 16:15:39 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_printf(int c);
int	ft_putnbr_printf(int c);
int	ft_putptr_printf(unsigned long c);
int	ft_putstr_printf(char *c);
int	ft_putuint_printf(unsigned int c);
int	ft_putulhex_printf(unsigned int c, const char *format);

#endif
