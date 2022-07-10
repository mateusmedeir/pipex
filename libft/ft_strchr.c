/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:01:56 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/24 17:32:41 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pointer;

	pointer = (char *)s;
	while (*pointer != '\0')
	{
		if (*pointer == c)
			return ((char *)pointer);
		else
			pointer++;
	}
	if (*pointer == c)
		return ((char *)pointer);
	return (NULL);
}
