/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:20:18 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/21 12:20:20 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_files[2];

	if (argc >= 5)
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
		ft_putstr_fd("Wrong arguments\n", 2);
	return (0);
}
