#include "libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

char *ft_find_path(char *cmd, char *envp[]);
void ft_execute_cmd(char *argv, char *envp[]);
void ft_pipex_primary(char *argv[], char *envp[], int *fd);
void ft_pipex_secondary(int argc, char *argv[], char *envp[], int *fd);
void ft_pipex(int argc, char *argv[], char *envp[]);
char    **ft_split_except(char const *s, char c);
