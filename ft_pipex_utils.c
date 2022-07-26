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

void ft_pipex_primary(char *argv, char *envp[], int *fd, int *fd_files)
{
    dup2(fd_files[0], 0);
	close(fd_files[0]);
    dup2(fd[1], 1);
	close(fd[1]);
    ft_execute_cmd(argv, envp);
}

void ft_pipex_secondary(char *argv, char *envp[], int *fd, int *fd_files)
{
    dup2(fd[0], 0);
    close(fd[0]);
    dup2(fd_files[1], 1);
    ft_execute_cmd(argv, envp);
}
