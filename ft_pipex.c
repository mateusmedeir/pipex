/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:36:03 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/08/01 12:49:33 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_primary(char *argv, char *envp[])
{
	int	fd[2];
	int	check;

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

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_files[2];

	if (argc >= 5)
	{
		fd_files[0] = open(argv[1], O_RDONLY);
		if (fd_files[0] == -1)
			ft_error_msg(argv[1]);
		fd_files[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 00700);
		if (fd_files[1] == -1)
			ft_error_msg(argv[argc - 1]);
		ft_pipex(argc, argv, envp, fd_files);
	}
	else
		write(2, "Too few arguments\n", 18);
	return (0);
}
