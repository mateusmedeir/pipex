#include "pipex.h"

void ft_pipex(char *argv[], char *envp[], int *fd_files)
{
	int	fd[2];
	int	check;

	pipe(fd);
	check = fork();

	if (check == 0)
	{
		close(fd[0]);
		ft_pipex_primary(argv[2], envp, fd, fd_files);
	}
	else
	{
		close(fd[1]);
		check = fork();
		if (check == 0)
			ft_pipex_secondary(argv[3], envp, fd, fd_files);
		else
			close(fd[0]);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	int	fd_files[2];

	fd_files[0] = open(argv[1], O_RDONLY);
	if (fd_files[0] == -1)
    {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }
	fd_files[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 00700);
	if (fd_files[1] == -1)
    {
        perror(argv[argc - 1]);
        exit(EXIT_FAILURE);
    }
	if (argc >= 5)
		ft_pipex(argv, envp, fd_files);
	waitpid(-1, NULL, 0);
	return (0);
}
