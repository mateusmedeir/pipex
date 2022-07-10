/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:09:38 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/25 13:05:03 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*pointer;
	int		counter;

	pointer = malloc((ft_strlen (s) + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	counter = 0;
	while (s[counter] != '\0')
	{
		pointer[counter] = (*f)(counter, s[counter]);
		counter++;
	}
	pointer[counter] = '\0';
	return (pointer);
}
