#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

void ft_execute_cmd(char *cmd[])
{
	char	*path;
	int		check;

	path = ft_strjoin("/bin/", cmd[0]);
	check = execve(path, cmd, NULL);
	if (check < 0)
	{
		free(path);
		path = ft_strjoin("/usr/bin/", cmd[0]);
		check = execve(path, cmd, NULL);
		if (check < 0)
			perror("could not execute execve");
	}
}

void ft_pipex_primary(char *argv[], int *fd)
{
	char	*tmp;
	char	**cmd;

	tmp = ft_strjoin(ft_strjoin(argv[2], " "), argv[1]);
	cmd = ft_split(tmp, ' ');
	free(tmp);
	dup2(fd[1], 1);
	close(fd[1]);
	ft_execute_cmd(cmd);
}

void ft_pipex_secondary(char *argv[], int *fd)
{
	int		fd_file;
	char	**cmd;

    cmd = ft_split(argv[3], ' ');
	fd_file = open(argv[4], O_WRONLY | O_TRUNC);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(fd_file, 1);
	ft_execute_cmd(cmd);
}

void ft_pipex(int argc, char *argv[])
{
	int		fd_file;
	int		fd[2];
	int		check;
	int		w;

	pipe(fd);

	check = fork();

	if (check == 0)
	{
		close(fd[0]);
		ft_pipex_primary(argv, fd);
	}
	else
	{
		close(fd[1]);
		check = fork();
		if (check == 0)
			ft_pipex_secondary(argv, fd);
		else
			close(fd[0]);
	}
	wait(&w);
}

int main(int argc, char *argv[])
{
	ft_pipex(argc, argv);
	return (0);
}

// PATH=/usr/bin/
