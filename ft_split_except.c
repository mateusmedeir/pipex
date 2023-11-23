/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_except.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:20:48 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/21 12:20:50 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_all(char **pointer, int split)
{
	while (split >= 0)
	{
		free (pointer[split]);
		split--;
	}
	free (pointer);
}

static int	check_quote(char const *s)
{
	int		counter;
	char	quote;

	counter = 1;
	quote = s[0];
	while (s[counter])
	{
		if (s[counter] == quote)
			return (counter);
		counter++;
	}
	return (0);
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
		if ((s[counter] == 34 || s[counter] == 39)
			&& check_quote(s + counter) > 0)
			counter += check_quote(s + counter);
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
	{
		if ((s[size] == 34 || s[size] == 39) && check_quote(s + size) > 0)
		{
			size = check_quote(s + size) - 1;
			s++;
			break ;
		}
		size++;
	}
	pointer[split] = ft_substr (s, 0, size);
	if (!pointer[split])
	{
		free_all (pointer, split);
		return (-1);
	}
	return (size);
}

char	**ft_split_except(char const *s, char c)
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
