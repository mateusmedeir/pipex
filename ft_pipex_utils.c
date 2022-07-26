#include "pipex.h"

char *ft_find_path(char *cmd, char *envp[])
{
    char **full_path;
    char    *tmp;
    char    *path;
    int     counter;

    while (!ft_strnstr(*envp, "PATH", 5))
        envp++;
    *envp +=  5;
    full_path = ft_split(*envp, ':');
    counter= 0;
    while(full_path[counter])
    {
	tmp = ft_strjoin(full_path[counter++], "/");
        path = ft_strjoin(tmp, cmd);
	free(tmp);
        if (access(path, F_OK | X_OK) == 0)
		return (path);
        free(path);
    }
    return (NULL);
}

void ft_execute_cmd(char *argv, char *envp[])
{
	char    **cmd;
    char    *path;

    cmd = ft_split_except(argv, ' ');
    path = ft_find_path(cmd[0], envp);
    if (!path)
    {
	    write(2, cmd[0], ft_strlen(cmd[0]));
	    write(2, ": Command not found\n", 20);
	    exit(EXIT_FAILURE);
    }
    execve(path, cmd, envp);
}

void ft_pipex_primary(char *argv[], char *envp[], int *fd)
{
    int	fd_file;

    fd_file = open(argv[1], O_RDONLY);
    if (fd_file == -1)
    {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }
    dup2(fd_file, 0);
	close(fd_file);
    dup2(fd[1], 1);
	close(fd[1]);
    ft_execute_cmd(argv[2], envp);
}

void ft_pipex_secondary(int argc, char *argv[], char *envp[], int *fd)
{
    int     fd_file;

    fd_file = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 00700);
    if (fd_file == -1)
    {
	    perror(argv[argc - 1]);
	    exit(EXIT_FAILURE);
    }
    dup2(fd[0], 0);
    close(fd[0]);
    dup2(fd_file, 1);
    ft_execute_cmd(argv[3], envp);
}
