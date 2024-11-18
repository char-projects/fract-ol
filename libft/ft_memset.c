/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:47:23 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:47:25 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fills memory with a constant byte (n)

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)(s + i)) = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	// Test 1:
	char str1[50] = "Hello, World!";
	printf("Test 1 before: %s\n", str1);
	ft_memset(str1, 65, 13); // Fills first 13 bytes of str1 with c
	printf("Test 1 after: %s\n", str1);

	// Test 2:
	char str2[50] = "Hello Málaga!";
	printf("\nTest2 before: %s\n", str2);
	ft_memset(str2, 65, 5);  // Fills first 5 bytes of str2 with c
	printf("Test 2 after: %s\n", str2);

	// Test 3:
	char str3[50] = "abcdefghijklmnopqrstuvwxyz";
	printf("\nTest 3 before: %s\n", str3);
	ft_memset(str3, 65, 3);  // Fills first 13 bytes of str3 with c
	printf("Test 3 after: %s\n", str3);

	return (0);
}
*/