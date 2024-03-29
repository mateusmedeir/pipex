/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:20:35 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/21 12:20:37 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_primary(char *argv, char *envp[])
{
	int		fd[2];
	pid_t	check;

	pipe(fd);
	check = fork();
	if (check == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		ft_execute_cmd(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
}

void	ft_pipex_secondary(char *argv, char *envp[], int *fd_files)
{
	close(fd_files[0]);
	dup2(fd_files[1], 1);
	close(fd_files[1]);
	ft_execute_cmd(argv, envp);
}

void	ft_pipex(int argc, char *argv[], char *envp[], int *fd_files)
{
	int	counter;

	counter = 1;
	dup2(fd_files[0], 0);
	while (++counter <= argc - 2)
	{
		if (counter < argc - 2)
			ft_pipex_primary(argv[counter], envp);
		else
			ft_pipex_secondary(argv[counter], envp, fd_files);
	}
	waitpid(-1, NULL, 0);
}
