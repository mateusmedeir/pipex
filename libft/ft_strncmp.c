/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:02:16 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/25 12:17:47 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			counter;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	counter = 0;
	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (p_s1[counter] == p_s2[counter] && p_s1[counter]
		&& p_s2[counter] && counter < n - 1)
		counter++;
	return (p_s1[counter] - p_s2[counter]);
}
