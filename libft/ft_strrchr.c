/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:02:05 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/19 12:37:22 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pointer;
	char	*save;

	pointer = (char *)s;
	save = NULL;
	while (*pointer != '\0')
	{
		if (*pointer == (char)c)
			save = pointer;
		pointer++;
	}
	if (*pointer == (char)c)
		save = pointer;
	return (save);
}
