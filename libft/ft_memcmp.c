/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:46:56 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/12 12:08:25 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Compares the first n bytes of the memory areas s1 and s2

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	int	res;

	if (argc <= 3)
	{
		fprintf(stderr, "Usage: %s <str1> <str2> [<len>]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
		res = ft_memcmp(argv[1], argv[2], atoi(argv[3]));
	if (res == 0)
	{
		printf("<str1> and <str2> are equal");
		if (argc > 3)
			printf(" in the first %d bytes\n", atoi(argv[3]));
	}
	else if (res < 0)
		printf("<str1> is less than <str2> (%d)\n", res);
	else
		printf("<str1> is greater than <str2> (%d)\n", res);
	exit(EXIT_SUCCESS);
}
*/