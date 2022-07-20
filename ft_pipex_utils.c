#include "pipex.h"

char *ft_find_path(char *cmd, char *envp[], int *fd)
{
    char    **tmp;
    char    *path;
    int     counter;
    int     check;

    while (!ft_strnstr(*envp, "PATH", 5))
        envp++;
    *envp +=  5;
    tmp = ft_split(*envp, ':');
    counter= 0;
    check = -1;
    while(check != 0 && tmp[counter])
    {
        path = ft_strjoin(ft_strjoin(tmp[counter++], "/"), cmd);
        check = access(path, F_OK | X_OK);
        if (check != 0)
            free(path);
    }
	if (!tmp[counter])
	{
		perror(cmd);
		close(fd[0]);
		close(fd[1]);
	}
    return (path);
}

void ft_execute_cmd(char *cmd[], char *path, char *envp[])
{
    int check;

    check = execve(path, cmd, envp);
    if (check < 0)
        perror("could not execute execve");
}

void ft_pipex_primary(char *argv[], char *envp[], int *fd)
{
    int	fd_file;
    char    **cmd;
    char    *path;

    cmd = ft_split_except(argv[2], ' ');
    path = ft_find_path(cmd[0], envp, fd);
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
    path = ft_find_path(cmd[0], envp, fd);
	fd_file = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 00700);
    dup2(fd[0], 0);
    close(fd[0]);
    dup2(fd_file, 1);
    ft_execute_cmd(cmd, path, envp);
}
