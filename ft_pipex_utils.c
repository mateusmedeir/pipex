#include "pipex.h"

char *ft_find_path(char *cmd, char *envp[])
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
    while(check != 0)
    {
        path = ft_strjoin(ft_strjoin(tmp[counter++], "/"), cmd);
        check = access(path, 0);
        if (check != 0)
            free(path);
    }
    return (path);
}

void ft_execute_cmd(char *cmd[], char *path)
{
    int check;

    check = execve(path, cmd, NULL);
    if (check < 0)
        perror("could not execute execve");
}

void ft_pipex_primary(char *argv[], char *envp[], int *fd)
{
    char    *tmp;
    char    **cmd;
    char    *path;

    tmp = ft_strjoin(ft_strjoin(argv[2], " "), argv[1]);
    cmd = ft_split(tmp, ' ');
    free(tmp);
    dup2(fd[1], 1);
    close(fd[1]);
    path = ft_find_path(cmd[0], envp);
    ft_execute_cmd(cmd, path);
}

void ft_pipex_secondary(char *argv[], char *envp[], int *fd)
{
    int     fd_file;
    char    **cmd;
    char    *path;

    cmd = ft_split(argv[3], ' ');
    fd_file = open(argv[4], O_WRONLY | O_TRUNC);
    dup2(fd[0], 0);
    close(fd[0]);
    dup2(fd_file, 1);
    path = ft_find_path(cmd[0], envp);
    ft_execute_cmd(cmd, path);
}
