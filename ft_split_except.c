/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_except.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:03:28 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/07/21 08:27:50 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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
		if (s[counter] == 39 && check == 0)
			check = 1;
		else if (s[counter] == 39 && check == 1)
			check = 0;
		if (s[counter] == c && (counter != 0 || s[counter - 1] != c)
				&& check == 0)
			split++;
		counter++;
	}
	return (split + 1);
}

static int	put_string(char **pointer, int split, char const *s, char c)
{
	int	size;
	int	start;

	size = 0;
	start = 0;
	if (s[size] == 39)
		start++;
	while (s[size + start] != '\0' && (s[size + start] != c || start == 1))
	{
		size++;
		if (s[size + start] == 39 && start == 1)
		{
			start++;
			break;
		}
	}
	pointer[split] = ft_substr (s, start - (start > 0), size + (start == 1));
	if (!pointer[split])
	{
		free_all (pointer, split);
		return (-1);
	}
	if (start == 1)
		--start;
	return (size + start);
}

char	**ft_split_except(char const *s, char c)
{
	char	**pointer;
	int		counter;
	int		split;
	int		max;

	split = 0;
	max = how_many_splits(s, c);
	pointer = (char **)malloc((max + 1) * sizeof(char *));
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
