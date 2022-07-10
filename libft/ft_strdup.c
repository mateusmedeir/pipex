/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:16:10 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/25 13:03:33 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	int		counter;

	pointer = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	counter = 0;
	while (s1[counter] != '\0')
	{
		pointer[counter] = s1[counter];
		counter++;
	}
	pointer[counter] = '\0';
	return (pointer);
}
