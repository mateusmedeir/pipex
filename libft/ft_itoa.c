/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:56:40 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/25 16:11:11 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_size(long int n)
{
	int	counter;

	counter = 1;
	if (n < 0)
	{
		counter++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char		*pointer;
	int			counter;
	int			signal;
	long int	value;

	value = (long int)n;
	counter = check_size(value);
	pointer = malloc((counter + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	signal = 0;
	if (value < 0)
	{
		pointer[0] = '-';
		value *= -1;
		signal = 1;
	}
	pointer[counter--] = '\0';
	while (counter >= signal)
	{
		pointer[counter--] = ((value % 10) + '0');
		value /= 10;
	}
	return (pointer);
}
