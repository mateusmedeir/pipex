/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:58:31 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/24 16:14:47 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;
	char	*pointer;

	counter = 0;
	pointer = (char *)b;
	while (counter < len)
	{
		pointer[counter] = (char)c;
		counter++;
	}
	return ((void *)pointer);
}
