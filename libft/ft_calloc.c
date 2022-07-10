/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:03:58 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/25 13:02:41 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	ft_bzero (pointer, count * size);
	return (pointer);
}
