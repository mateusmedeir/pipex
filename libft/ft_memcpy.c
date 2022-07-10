/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:01:10 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/24 16:39:10 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p_dst;
	char	*p_src;
	size_t	counter;

	p_dst = (char *)dst;
	p_src = (char *)src;
	if (!p_dst && !p_src)
		return (NULL);
	counter = 0;
	while (counter < n)
	{
		p_dst[counter] = p_src[counter];
		counter++;
	}
	return (p_dst);
}
