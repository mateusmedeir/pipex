/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:36:08 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/08/01 12:45:04 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_msg(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_free_all(char *array[])
{
	int	counter;

	counter = 0;
	while (array[counter])
		free(array[counter++]);
	free(array);
}

char	*ft_find_path(char *cmd, char *envp[])
{
	char	**full_path;
	char	*tmp;
	char	*path;
	int		counter;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	while (!ft_strnstr(*envp, "PATH", 4))
		envp++;
	full_path = ft_split(*envp + 5, ':');
	counter = 0;
	while (full_path[counter])
	{
		tmp = ft_strjoin(full_path[counter++], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
	}
	ft_free_all(full_path);
	return (NULL);
}

void	ft_execute_cmd(char *argv, char *envp[])
{
	char	**cmd;
	char	*path;

	cmd = ft_split_except(argv, ' ');
	path = ft_find_path(cmd[0], envp);
	if (!path || access(path, F_OK | X_OK) != 0)
	{
		ft_error_msg(cmd[0]);
		ft_free_all(cmd);
	}
	else
		execve(path, cmd, envp);
}
