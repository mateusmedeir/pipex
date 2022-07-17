#include "pipex.h"

void ft_pipex(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		check;
	int		w;

	pipe(fd);
	check = fork();

	if (check == 0)
	{
		close(fd[0]);
		ft_pipex_primary(argv, envp, fd);
	}
	else
	{
		close(fd[1]);
		check = fork();
		if (check == 0)
			ft_pipex_secondary(argc, argv, envp, fd);
		else
			close(fd[0]);
	}
	wait(&w);
}

int main(int argc, char *argv[], char *envp[])
{
	ft_pipex(argc, argv, envp);
	return (0);
}
