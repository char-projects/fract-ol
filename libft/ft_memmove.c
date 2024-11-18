/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:47:14 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:47:16 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (n--)
			*cdest++ = *csrc++;
	}
	else if (dest > src)
	{
		cdest += n - 1;
		csrc += n - 1;
		while (n--)
			*cdest-- = *csrc--;
	}
	return (dest);
}
/*
int	main(void)
{
	// Test 1: No overlap, src < dest
	char str1[50] = "Hello, World!";
	printf("Test 1 before: %s\n", str1);
	// Move first 13 characters 13 positions ahead
	ft_memmove(str1 + 13, str1, 13);
	printf("Test 1 after: %s\n", str1);

	// Test 2: Overlap, src < dest
	char str2[50] = "abcdefghijklmnopqrstuvwxyz";
	printf("\nTest 2 before: %s\n", str2);
	// Move first 10 characters 5 positions ahead
	ft_memmove(str2 + 5, str2, 10);
	printf("Test 2 after: %s\n", str2);

	// Test 3: Overlap, src > dest
	char str3[50] = "abcdefghijklmnopqrstuvwxyz";
	printf("\nTest 3 before: %s\n", str3);
	// Move characters starting from position 5 to the start
	ft_memmove(str3, str3 + 5, 10);
	printf("Test 3 after: %s\n", str3);
	
	return (0);
}
*/
