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

void ft_execute_cmd(char *cmd[], char *path, char *envp[])
{
    if (!path)
    {
	    perror(cmd[0]);
    }
    execve(path, cmd, envp);
}

void ft_pipex_primary(char *argv[], char *envp[], int *fd)
{
    int	fd_file;
    char    **cmd;
    char    *path;

    cmd = ft_split_except(argv[2], ' ');
    path = ft_find_path(cmd[0], envp);
	fd_file = open(argv[1], O_RDONLY);
    dup2(fd_file, 0);
    dup2(fd[1], 1);
    ft_execute_cmd(cmd, path, envp);
    close(fd_file);
    close(fd[1]);
}

void ft_pipex_secondary(int argc, char *argv[], char *envp[], int *fd)
{
    int     fd_file;
    char    **cmd;
    char    *path;

    cmd = ft_split_except(argv[3], ' ');
    path = ft_find_path(cmd[0], envp);
	fd_file = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 00700);
    dup2(fd[0], 0);
    close(fd[0]);
    dup2(fd_file, 1);
    ft_execute_cmd(cmd, path, envp);
}
