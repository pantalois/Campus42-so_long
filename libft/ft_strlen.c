/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:05:01 by loigonza          #+#    #+#             */
/*   Updated: 2024/08/02 18:19:07 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
		i++;
	return (i);
}

/*
int	main(void)
{
	const char	*str;
	
	str = "asdfgdfdgdhthdgd";


	ft_strlen(str);

}
*/
