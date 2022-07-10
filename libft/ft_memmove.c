/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:31:30 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/24 16:20:11 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*p_dst;
	char	*p_src;
	size_t	counter;

	p_src = (char *) src;
	p_dst = (char *) dst;
	if (!p_src && !p_dst)
		return (NULL);
	if (p_dst < p_src)
	{
		return (ft_memcpy(dst, src, len));
	}
	else
	{
		counter = len - 1;
		while (counter + 1 > 0)
		{
			p_dst[counter] = p_src[counter];
			counter--;
		}	
	}
	return (p_dst);
}
