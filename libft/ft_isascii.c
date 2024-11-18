/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:44:54 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/12 12:04:17 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks whether c is a 7-bit unsigned char value that 
fits  into the ASCII character set */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*
int	main(void)
{
	// Should return 1
	printf("Test 0: %d\n", ft_isascii(0));
	printf("Test 1: %d\n", ft_isascii(26));
	printf("Test 2: %d\n", ft_isascii(103));

	// Should return 0
	printf("Test 3: %d\n", ft_isascii(130));
	printf("Test 4: %d\n", ft_isascii(-1));

	return (0);
}
*/