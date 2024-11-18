/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:03:35 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/12 11:58:51 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts the initial portion of the string pointed 
to by nptr to an int */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (res < -2147483648)
			res = 2147483648;
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)res * (int)sign);
}
/*
int	main(void)
{
	char	*test1;
	char	*test2;
		
	test1 = "123ab45";
	test2 = "  \n	\v76139.23f";
	printf("Test 1: %d\n", ft_atoi(test1));
	printf("Test 1: %d\n", ft_atoi(test2));
	return (0);
}
*/
