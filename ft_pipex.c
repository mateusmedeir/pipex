#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

void ft_freeall(**array)
{
	while (*array)
		free(*array++);
	free(*array);
	free(array);
}

void ft_pipex(int argc, char *argv[])
{
	char    *tmp;
    char    *path;
    char    **cmds;
    int     value;
    int     fd;

    tmp = ft_strjoin(ft_strjoin(argv[2], " "), argv[1]);
    cmds = ft_split(tmp, ' ');
    free(tmp);
    path = ft_strjoin("/bin/", cmds[0]);
    fd = open(argv[3], O_WRONLY | O_TRUNC);
    dup2(fd, 1);
    value = execve(path, cmds, NULL);
    if (value == -1)
        perror("Could not execute execve");
}

int main(int argc, char *argv[])
{
	ft_pipex(argc, argv);
	return (0);
}

// PATH=/usr/bin/
