/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:49:35 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:49:37 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
		res = ft_strncmp(argv[1], argv[2], atoi(argv[3]));
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