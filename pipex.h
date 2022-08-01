/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:28:10 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/08/01 13:28:32 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

void	ft_error_msg(char *str);
void	ft_free_all(char *array[]);
char	*ft_find_path(char *cmd, char *envp[]);
void	ft_execute_cmd(char *argv, char *envp[]);
void	ft_pipex(int argc, char *argv[], char *envp[], int *fd_files);
void	ft_pipex_primary(char *argv, char *envp[]);
void	ft_pipex_secondary(char *argv, char *envp[], int *fd_files);
char	**ft_split_except(char const *s, char c);

#endif
