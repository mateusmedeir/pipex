#include "libft/libft.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	char *tmp;
	char *path;
	char **cmds;
	int value;

	tmp = ft_strjoin(ft_strjoin(argv[2], " "), argv[1]);
	cmds = ft_split(tmp, ' ');
	path = ft_strjoin("/usr/bin/", cmds[0]);
	value = execve(path, cmds, NULL);
	if (value == -1)
		perror("Could not execute execve");
	printf("Oops, something went wrong!\n");
	return (0);
}

// PATH=/usr/bin/
