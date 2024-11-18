/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:49:43 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:49:45 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0' || little == NULL)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && i + j < len)
			{
				if (little[j + 1] == '\0')
					return ((char *)big + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *test0 = "Hello, world!";
	const char *test1 = "world";
	const char *test2 = "abc";
	const char *test3 = "bc";
	const char *test4 = "Good morning!!";
        const char *test5 = "Good";
	char *res = ft_strnstr(test0, test1, 30);
	if (res != NULL)
		printf("Test 0: '%s' found at position %ld in \"%s\"\n",
			test1, res - test0, test0);
	else
		printf("Test 0: '%s' not found in \"%s\"\n", test1, test0);    
	res = ft_strnstr(test2, test3, 30);
	if (res != NULL)
		printf("Test 1: '%s' found at position %ld in \"%s\"\n",
			test3, res - test2, test2);
	else
		printf("Test 1: '%s' not found in \"%s\"\n", test3, test2);
	res = ft_strnstr(test3, test4, 30);
	if (res != NULL)
		printf("Test 2: \"%s\" found in \"%ld\" at position %s\n",
			test4, res - test3, test3);
	else
		printf("Test 2: \"%s\" not found in \"%s\"\n", test4, test3);
	res = ft_strnstr(test4, test5, 30);
	if (res != NULL)
		printf("Test 3: '%s' found at position %ld in \"%s\"\n",
			test5, res - test4, test4);
	else
		printf("Test 3: '%s' not found in \"%s\"\n", test5, test4);
	return (0);
}
*/
