/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:18 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/25 12:16:21 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	writechar(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		writechar('-', fd);
		writechar('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		writechar('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		writechar(n + '0', fd);
}
