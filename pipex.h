#include "libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

char *ft_find_path(char *cmd, char *envp[]);
void ft_execute_cmd(char *argv, char *envp[]);
void ft_pipex_primary(char *argv, char *envp[], int *fd, int *fd_files);
void ft_pipex_secondary(char *argv, char *envp[], int *fd, int *fd_files);
void ft_pipex(char *argv[], char *envp[], int *fd_files);
char    **ft_split_except(char const *s, char c);
