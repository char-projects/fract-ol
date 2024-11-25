/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:36:45 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 22:30:13 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnbr(int n)
{
	int		count;
	char	c;

	count = 1;
	while (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			count = 11;
			break ;
		}
		write(1, "-", 1);
		count++;
		n *= (-1);
	}
	if (n >= 0)
	{
		if (n > 9)
			count += ft_putnbr(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen_printf(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_putstr(char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen_printf(s)));
}

int	ft_count(unsigned int ui, unsigned int base)
{
	int	count;

	count = 1;
	while (ui >= base)
	{
		ui /= base;
		count++;
	}
	return (count);
}
