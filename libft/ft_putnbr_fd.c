/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:47:57 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:47:59 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	while (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			break ;
		}
		write(fd, "-", 1);
		n *= (-1);
	}
	if (n >= 0)
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		write (fd, &c, 1);
	}
}

/*
int	main(void)
{
	int n = -2147483648;
	ft_putnbr_fd(n, 1);
}
*/
