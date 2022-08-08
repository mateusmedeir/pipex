/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:55:20 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/08/08 10:10:31 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_files[2];

	if (argc == 5)
	{
		fd_files[0] = open(argv[1], O_RDONLY);
		if (fd_files[0] == -1)
			ft_error_msg(argv[1]);
		fd_files[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 00700);
		if (fd_files[1] == -1)
			ft_error_msg(argv[argc - 1]);
		ft_pipex(argc, argv, envp, fd_files);
	}
	else
		write(2, "Wrong arguments\n", 16);
	return (0);
}
