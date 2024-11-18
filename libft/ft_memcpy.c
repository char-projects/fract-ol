/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:47:06 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:47:08 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	// Test 1:
	char str1[50] = "Hello, World!";
	printf("Test 1 before: %s\n", str1);
	ft_memcpy(str1 + 13, str1, 13); // Copy first 13 characters
	printf("Test 1 after: %s\n", str1);

	// Test 2:
	char str2[50] = "Hello Málaga!";
	printf("\nTest2 before: %s\n", str2);
	ft_memcpy(str2 + 14, str2, 5);  // Copy first 5 characters
	printf("Test 2 after: %s\n", str2);

	// Test 3:
	char str3[50] = "abcdefghijklmnopqrstuvwxyz";
	printf("\nTest 3 before: %s\n", str3);
	ft_memcpy(str3 + 26, str3, 3);  // Copy first 3 characters
	printf("Test 3 after: %s\n", str3);
	
	return (0);
}
*/
