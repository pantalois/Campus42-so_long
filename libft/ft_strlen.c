/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:05:01 by loigonza          #+#    #+#             */
/*   Updated: 2024/07/09 18:10:53 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *line)
{
	int	i;

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
