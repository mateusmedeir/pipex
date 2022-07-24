/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:03:28 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/30 13:04:14 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **pointer, int split)
{
	while (split >= 0)
	{
		free (pointer[split]);
		split--;
	}
	free (pointer);
}

static int	how_many_splits(char const *s, char c)
{
	int	split;
	int	counter;
	int	check;

	split = 0;
	counter = 0;
	check = 0;
	while (s[counter])
	{
		if (s[counter] != c && check == 0)
		{
			split++;
			check = 1;
		}
		else if (s[counter] == c)
			check = 0;
		counter++;
	}
	return (split);
}

static int	put_string(char **pointer, int split, char const *s, char c)
{
	int	size;

	size = 0;
	while (s[size] != '\0' && s[size] != c)
		size++;
	pointer[split] = ft_substr (s, 0, size);
	if (!pointer[split])
	{
		free_all (pointer, split);
		return (-1);
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**pointer;
	int		counter;
	int		split;
	int		max;

	split = 0;
	max = how_many_splits(s, c);
	pointer = malloc((max + 1) * sizeof(char *));
	if (!pointer)
		return (NULL);
	while (split < max && *s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			counter = put_string(pointer, split, s, c);
			if (counter == -1)
				return (NULL);
			s += counter;
			split++;
		}
	}
	pointer[split] = NULL;
	return (pointer);
}
