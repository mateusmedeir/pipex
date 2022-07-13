#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

void ft_pipex(int argc, char *argv[])
{
	int		fd_file;
	int		fd[2];
	char	**cmds1;
	char	*cmds2[] = {"wc", "-l", NULL};
	char	*tmp;
	char	*path;
	int		check;
	int		w;

	pipe(fd);

	check = fork();

	if (check == 0)
	{
		close(fd[0]);

		tmp = ft_strjoin(ft_strjoin(argv[2], " "), argv[1]);
		cmds1 = ft_split(tmp, ' ');
		path = ft_strjoin("/bin/", cmds1[0]);
		free(tmp);

		dup2(fd[1], 1);
		close(fd[1]);

		execve(path, cmds1, NULL);
	}
	else
	{
		close(fd[1]);

		check = fork();

		if (check == 0)
		{
			fd_file = open(argv[4], O_WRONLY | O_TRUNC);
			dup2(fd[0], 0);
			close(fd[0]);

			dup2(fd_file, 1);

			execve("/usr/bin/wc", cmds2, NULL);
		}
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
