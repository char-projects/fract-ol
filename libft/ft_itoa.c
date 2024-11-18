/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:45:30 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:03:59 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbr(long n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		i;
	long	nbr;

	nbr = (long)n;
	i = count_nbr(nbr);
	array = (char *)ft_calloc(sizeof(char), i + 1);
	if (!array)
		return (0);
	array[i] = '\0';
	if (nbr < 0)
	{
		array[0] = '-';
		nbr *= -1;
	}
	else if (nbr == 0)
		array[0] = '0';
	while (nbr > 0)
	{
		array[--i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (array);
}
/*
int	main(void)
{
	printf("ft_itoa(0): %s\n", ft_itoa(0));
	printf("ft_itoa(123): %s\n", ft_itoa(123));
	printf("ft_itoa(-123): %s\n", ft_itoa(-123));
	printf("ft_itoa(2147483647): %s\n", ft_itoa(2147483647));
	printf("ft_itoa(-2147483648): %s\n", ft_itoa(-2147483648));
	return (0);
}
*/
