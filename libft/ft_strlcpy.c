/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:52:15 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/25 12:17:13 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	counter;

	counter = 0;
	size = ft_strlen(src);
	if (dstsize == 0)
		return (size);
	while (counter < size && counter < dstsize - 1)
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (size);
}
